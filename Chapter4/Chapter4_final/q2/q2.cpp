#include "arithmetic_input.h"
#include "arithmetic_operation.h"
#include "double_input.h"
#include <iostream>

int main() {

    double first_num {double_input()};
    double second_num {double_input()};

    char arithmetic_op {arithmetic_input() };
    
    arithmetic_operation(first_num, second_num, arithmetic_op);
    return 0;
}

