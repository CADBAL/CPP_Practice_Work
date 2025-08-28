#include "double_input.h"
#include <iostream>
double double_input() {
    double double_num {};
    std::cout << "Enter a double value: ";
    std::cin >> double_num;
    return double_num;
}

