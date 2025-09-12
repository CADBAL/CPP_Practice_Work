#include <iostream>

constexpr int isEven(int n) {
    if ((n % 2) == 0) {
        std::cout << n << " is even" << "\n";
        return true;
    } else {
        return false;
    }
}

int main() {
    
    std::cout << "Enter an integer: ";
     int n {};
    std::cin >> n;

    if ((isEven(n)) == true) {
        std::cout << n << " is even" << "\n";
        return 0;
    } else {
        std::cout << n << " is odd" << "\n";
        return 0;
    }
}

