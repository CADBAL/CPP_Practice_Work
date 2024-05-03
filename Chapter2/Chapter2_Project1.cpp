#include <iostream>

int double_number(int num) {
    return num * 2;
}

int main() {

    int input {0};

    std::cout << "Enter a number that will be doubled: ";
    std::cin >> input;
    std::cout << "Doubled number is: ";
    std::cout << double_number(input) << "\n";

    return 0;
}
