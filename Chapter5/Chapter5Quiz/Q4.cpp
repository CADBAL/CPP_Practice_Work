#include <iostream>
#include <string>

int main() {

    std::string name1 {};
    int age1 {};
    std::string name2 {};
    int age2 {};

    std:: cout << "Enter the name of person #1: ";
    std::getline(std::cin, name1);

    std::cout << "Enter the age of " << name1 << ": "
    std::cin >> age1;

    std::cout << "Enter the name of person #2: ";
    std::getline(std::cin >> std::ws, name2) ;

    std::cout << "Enter the age of " << name2 << ": ";
    std::cin >> age2;

    if age1 == age2 {
        std::cout << name1 << "(age " << age1 << ") " << "is the same age as " << name2 "(age " << age2 << ")";
    } else if age1 > age2 {
        std::cout << name1 << "(age " << age1 << ") " << "is older than " << name2 "(age " << age2 << ")";
    } else if age2 > age1 {
        std::cout << name2 << "(age " << age2 << ") " << "is older than " << name1 "(age " << age1 << ")";
    }
}

// Q5) age1 can't be a constexpr because std::cin >> (input operator) can not be a constant
