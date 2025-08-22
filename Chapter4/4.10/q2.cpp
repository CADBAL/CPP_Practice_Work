#include <iostream>


bool is_prime(int x) {
    std::cout << "enter a number betwenn 0 and 9" << "\n";

    std::cin >> x;

    if ((x == 2) || (x == 3) || (x == 5) || (x == 7)) {
        std::cout << "The digit is prime" << "\n";
        return true;
    } else {
        std::cout << "The digit is not prime" << "\n";
        return false;
    }
}

int main() {
    int x {};
    is_prime(x);
    return 0;
}
