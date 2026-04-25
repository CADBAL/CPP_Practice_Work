#include "raylib.h"
#include "raymath.h"

// =====================================================
// PLAYER
// =====================================================
struct Player {
    Vector3 position = { 0, 1, 0 };
    Vector3 velocity = { 0 };

    float yaw = 0.0f;
    float pitch = 0.0f;

    bool grounded = true;
};

// =====================================================
// DOOR
// =====================================================
struct Door {
    Vector3 position;
    float width;
    float height;
    int leadsToRoom;
};

// =====================================================
// ROOM
// =====================================================
struct Room {
    Vector3 center;
    Door doors[4];
};

// =====================================================
// ENGINE
// =====================================================
class Engine {
public:
    static const int ROOM_COUNT = 5;

    Camera3D camera = { 0 };
    Player player;

    Room rooms[ROOM_COUNT];
    int currentRoom = 0;

    const float sensitivity = 0.01f;
    const float speed = 6.0f;
    const float gravity = 9.8f;
    const float jumpForce = 5.0f;

    // -------------------------
    void initRooms() {
        // HUB (0)
        rooms[0].center = { 0, 0, 0 };

        rooms[0].doors[0] = {{ 0, 1, -5 }, 1, 2, 1};
        rooms[0].doors[1] = {{ 5, 1,  0 }, 1, 2, 2};
        rooms[0].doors[2] = {{ 0, 1,  5 }, 1, 2, 3};
        rooms[0].doors[3] = {{-5, 1,  0 }, 1, 2, 4};

        // ROOM 1
        rooms[1].center = { 20, 0, 0 };
        rooms[1].doors[0] = {{ 20, 1,  5 }, 1, 2, 0};

        // ROOM 2
        rooms[2].center = { -20, 0, 0 };
        rooms[2].doors[0] = {{ -20, 1, -5 }, 1, 2, 0};

        // ROOM 3
        rooms[3].center = { 0, 0, 20 };
        rooms[3].doors[0] = {{ 5, 1, 20 }, 1, 2, 0};

        // ROOM 4
        rooms[4].center = { 0, 0, -20 };
        rooms[4].doors[0] = {{ -5, 1, -20 }, 1, 2, 0};
    }

    // -------------------------
    void init() {
        InitWindow(800, 600, "FPS Engine - Rooms + Portals");
        SetTargetFPS(60);

        HideCursor();

        camera.fovy = 75.0f;
        camera.projection = CAMERA_PERSPECTIVE;

        player.position = { 0, 1, 0 };
        player.yaw = 0;
        player.pitch = 0;

        initRooms();
    }

    // =====================================================
    // CAMERA MATH (FPS STANDARD)
    // =====================================================
    Vector3 getForward() {
        float cosPitch = cosf(player.pitch);

        return {
            sinf(player.yaw) * cosPitch,
            sinf(player.pitch),
            cosf(player.yaw) * cosPitch
        };
    }

    Vector3 getRight() {
        return {
            sinf(player.yaw - PI / 2.0f),
            0,
            cosf(player.yaw - PI / 2.0f)
        };
    }

    // =====================================================
    // MOUSE LOOK (FIXED FPS INPUT)
    // =====================================================
    void updateLook() {
        Vector2 delta = GetMouseDelta();

        player.yaw   -= delta.x * sensitivity;
        player.pitch -= delta.y * sensitivity;

        const float limit = 1.5f;

        if (player.pitch > limit) player.pitch = limit;
        if (player.pitch < -limit) player.pitch = -limit;
    }

    // =====================================================
    // MOVEMENT
    // =====================================================
    void move(float dt) {
        Vector3 forward = getForward();
        Vector3 right = getRight();

        Vector3 moveDir = { 0 };

        if (IsKeyDown(KEY_W)) moveDir = Vector3Add(moveDir, forward);
        if (IsKeyDown(KEY_S)) moveDir = Vector3Subtract(moveDir, forward);
        if (IsKeyDown(KEY_D)) moveDir = Vector3Add(moveDir, right);
        if (IsKeyDown(KEY_A)) moveDir = Vector3Subtract(moveDir, right);

        moveDir.y = 0;
        moveDir = Vector3Normalize(moveDir);

        player.position = Vector3Add(
            player.position,
            Vector3Scale(moveDir, speed * dt)
        );
    }

    // =====================================================
    // PHYSICS
    // =====================================================
    void physics(float dt) {
        player.velocity.y -= gravity * dt;
        player.position.y += player.velocity.y * dt;

        if (player.position.y < 1.0f) {
            player.position.y = 1.0f;
            player.velocity.y = 0;
            player.grounded = true;
        }

        if (IsKeyPressed(KEY_SPACE) && player.grounded) {
            player.velocity.y = jumpForce;
            player.grounded = false;
        }
    }

    // =====================================================
    // CAMERA UPDATE
    // =====================================================
    void updateCamera() {
        Vector3 forward = getForward();

        camera.position = player.position;
        camera.target = Vector3Add(player.position, forward);
        camera.up = { 0, 1, 0 };
    }

    // =====================================================
    // DOOR HIT TEST
    // =====================================================
    bool isDoorHit(Door d, Ray ray) {
        BoundingBox box;

        box.min = {
            d.position.x - d.width,
            d.position.y - d.height,
            d.position.z - 0.2f
        };

        box.max = {
            d.position.x + d.width,
            d.position.y + d.height,
            d.position.z + 0.2f
        };

        RayCollision hit = GetRayCollisionBox(ray, box);
        return hit.hit;
    }

    // =====================================================
    // ROOM SWITCHING
    // =====================================================
    void checkDoorClick() {
        if (!IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) return;

        Ray ray = GetMouseRay(GetMousePosition(), camera);

        for (int i = 0; i < 4; i++) {
            Door d = rooms[currentRoom].doors[i];

            if (isDoorHit(d, ray)) {
                currentRoom = d.leadsToRoom;
                player.position = rooms[currentRoom].center + Vector3{0, 1, 0};
            }
        }
    }

    // =====================================================
    // ROOM DRAWING
    // =====================================================
    void drawRoom(int id) {
        Room r = rooms[id];

        float s = 5.0f;

        DrawPlane(r.center, {10, 10}, GRAY);
        DrawCube({r.center.x, 4, r.center.z}, 10, 0.2f, 10, BLACK);

        DrawCube({r.center.x, 2, r.center.z - s}, 10, 4, 0.2f, GREEN);
        DrawCube({r.center.x, 2, r.center.z + s}, 10, 4, 0.2f, GREEN);
        DrawCube({r.center.x - s, 2, r.center.z}, 0.2f, 4, 10, GREEN);
        DrawCube({r.center.x + s, 2, r.center.z}, 0.2f, 4, 10, GREEN);

        for (int i = 0; i < 4; i++) {
            DrawCube(r.doors[i].position,
                     r.doors[i].width,
                     r.doors[i].height,
                     0.2f,
                     YELLOW);
        }
    }

    // =====================================================
    // PORTAL VIEW (FAKE BUT EFFECTIVE)
    // =====================================================
    void drawPortalView(Door d) {
        Camera3D temp = camera;

        temp.position = d.position;
        temp.target = rooms[d.leadsToRoom].center + Vector3{0, 1, 0};

        BeginMode3D(temp);
        drawRoom(d.leadsToRoom);
        EndMode3D();
    }

    // =====================================================
    // RENDER
    // =====================================================
    void render() {
        BeginDrawing();
        ClearBackground(SKYBLUE);

        BeginMode3D(camera);

        drawRoom(currentRoom);

        // portal previews inside doors
        for (int i = 0; i < 4; i++) {
            drawPortalView(rooms[currentRoom].doors[i]);
        }

        EndMode3D();

        DrawText("WASD move | Mouse look | CLICK doors | SPACE jump", 10, 10, 20, BLACK);

        EndDrawing();
    }

    // =====================================================
    // MAIN LOOP
    // =====================================================
    void run() {
        init();

        while (!WindowShouldClose()) {
            float dt = GetFrameTime();

            updateLook();
            move(dt);
            physics(dt);
            updateCamera();
            checkDoorClick();
            render();
        }

        CloseWindow();
    }
};

// =====================================================
int main() {
    Engine engine;
    engine.run();
}
