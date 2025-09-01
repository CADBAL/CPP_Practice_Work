#include <iostream>
#include <string>

int main() {
    std::cout << "Enter your full name: ";
    std::string name {};
    std::getline(std::cin, name);

    std::cout << "Enter your age: ";
    int age {};
    std::cin >> age;

    std::cout << "Your age + length of your name is: " << (static_cast<int>(name.length()) + (age)) << "\n";

    return 0;
}
