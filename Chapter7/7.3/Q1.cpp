#include <iostream>

int main() {
    int smaller {};
    int larger {};

    std::cout << "Enter an integer: ";
    std::cin >> smaller;
    std::cout << "Enter a larger integer: ";
    std::cin >> larger;

    if (larger < smaller) {
        int temp_large { smaller }; // This is a temprary variable used to store the larger value in "smaller"
                                // so the value doesn't get overwritten in the next assignment.
        smaller = larger;
        larger = temp_large;
    } // temp_large dies here
    
    std::cout << "The smaller number is " << smaller << " and the larger number is " << larger << "\n";
} // "smaller" and "larger" die here
