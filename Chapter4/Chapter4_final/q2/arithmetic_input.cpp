#include "arithmetic_input.h"
#include <iostream>

char arithmetic_input() {
    char arithmetic_op {};
    std::cout << "Enter +, -,  *, or /: ";
    std::cin >> arithmetic_op;
    return arithmetic_op;
}
