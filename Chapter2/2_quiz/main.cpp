#include <iostream>
#include "io.h"

int main() {
    int user_num_1 {read_number()};
    int user_num_2 {read_number()};

    int answer {user_num_1 + user_num_2};

    write_answer(answer);
    return 0;
}
