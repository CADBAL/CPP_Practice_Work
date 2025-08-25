#include "arithmetic_operation.h"
#include <iostream>

bool arithmetic_operation(double first_num, double second_num, char arithmetic_op) {
    if (arithmetic_op != '*' && arithmetic_op != '+' && arithmetic_op != '-' && arithmetic_op != '/') {
        return false;
    } else if (arithmetic_op == '*') {
        std::cout << first_num << " " << arithmetic_op << " " << second_num << " is " << (first_num * second_num) << "\n";
        return true;
    } else if (arithmetic_op == '+') {
        std::cout << first_num << " " << arithmetic_op << " " << second_num << " is " << (first_num + second_num) << "\n";
        return true;
    } else if (arithmetic_op == '-') {
        std::cout << first_num << " " << arithmetic_op << " " << second_num << " is " << (first_num - second_num) << "\n";
        return true;
    } else if (arithmetic_op == '/') {
        std::cout << first_num << " " << arithmetic_op << " " << second_num << " is " << (first_num / second_num) << "\n";
        return true;
    } else {
        return true;
    }
}
