#include <iostream>

int main() {
    std::cout << "Enter an integer: ";

    int user_num {0};

    std::cin >> user_num;

    std::cout << "Double " << user_num << " is " << user_num * 2 << "\n";

    std::cout << "Triple " << user_num << " is " << user_num * 3 << "\n";

    return 0;
}
