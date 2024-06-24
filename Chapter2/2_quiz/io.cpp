#include <iostream>
#include "io.h"

int read_number() {
    int user_num {0};
    std::cin >> user_num;
    return user_num;
}

void write_answer(int answer) {
    std::cout << answer << "\n";
}
