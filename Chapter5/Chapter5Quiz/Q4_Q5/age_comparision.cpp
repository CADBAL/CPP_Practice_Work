#include "age_comparision.h"
#include <iostream>
#include <string>

void age_comparision(std::string name1, std::string name2, int age1, int age2) {
    if (age1 == age2) {
        std::cout << name1 << " (age " << age1 << ") " << "is the same age as " << name2 << " (age " << age2 << ")" << "\n";
    } else if (age1 > age2) {
        std::cout << name1 << " (age " << age1 << ") " << "is older than " << name2 << " (age " << age2 << ")" << "\n";
    } else if (age2 > age1) {
        std::cout << name2 << " (age " << age2 << ") " << "is older than " << name1 << " (age " << age1 << ")" << "\n";
    }
}
