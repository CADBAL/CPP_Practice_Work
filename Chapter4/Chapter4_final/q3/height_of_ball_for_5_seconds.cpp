#include "height_of_ball_for_5_seconds.h"
#include "read_current_height.h"
#include "read_initial_height.h"
#include <iostream>

void height_of_ball_for_5_seconds() {
    double initial_height { read_initial_height() };
    read_current_height(initial_height, 0);
    read_current_height(initial_height, 1);
    read_current_height(initial_height, 2);
    read_current_height(initial_height, 3);
    read_current_height(initial_height, 4);
    read_current_height(initial_height, 5);
}
