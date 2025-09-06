#include "input_name.h"
#include <iostream>
#include <string>

std::string input_name() {
    std::string name{};
    std::getline(std::cin >> std::ws, name);
    return name;
}
