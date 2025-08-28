#include "read_initial_height.h"
#include <iostream>

double read_initial_height() {
    double height {};
    std::cout << "Enter the height of the tower in metres: ";
    std::cin >> height;
    return  height;
}
