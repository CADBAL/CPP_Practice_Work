#include <iostream>

int main() {

    int first_user_num {0};
    int second_user_num {0};

    std::cout << "Enter an integer ";

    std::cin >> first_user_num;

    std::cout << "Enter another integer: ";

    std::cin >> second_user_num;

    std::cout << first_user_num << " + " << second_user_num << " is " 
    << first_user_num + second_user_num << "\n";

    std::cout << first_user_num << " - " << second_user_num << " is " 
    << first_user_num - second_user_num  << "\n";
}
