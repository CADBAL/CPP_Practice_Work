#include <iostream>

int main() {
    char x {};
    std::cout << "Enter a single character" << "\n";
    std::cin >> x;

    std::cout << "You entered " << x << " which has ASCII code " << static_cast<int>(x) << "." << "\n";

    return 0;
}
