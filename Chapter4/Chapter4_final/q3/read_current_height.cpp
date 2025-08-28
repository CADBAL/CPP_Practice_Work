#include <iostream>

void read_current_height(double initial_height, int time) {
    double distance_fallen = (9.8 * (time * time)) / 2;

    double current_height = initial_height - distance_fallen;

    if (current_height > 0) {
        std::cout << "At " << time  << " seconds, the ball is at a height of: " << current_height << "\n";
    } else {
        std::cout << "At " << time  << " seconds, the ball is on the ground" << "\n";
    }
}
