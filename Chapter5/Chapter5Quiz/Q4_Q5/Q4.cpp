#include "age_comparision.h"
#include "input_age.h"
#include "input_name.h"
#include <iostream>
#include <string>

int main() {

    std:: cout << "Enter the name of person #1: ";
    std::string name1 {input_name()};

    std::cout << "Enter the age of " << name1 << ": ";
    int age1 {input_age()};

    std::cout << "Enter the name of person #2: ";
    std::string name2 {input_name()};

    std::cout << "Enter the age of " << name2 << ": ";
    int age2 {input_age()};

    age_comparision(name1, name2, age1, age2); // This function compares the age between 2 different individuals.

}

// Q5) age1 can't be a constexpr because std::cin >> (input operator) can not be a constant
