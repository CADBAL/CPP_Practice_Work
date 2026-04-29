#include <iostream>

int main() {
    int user_input {};
    std::cout << "Input a number between 0 and 255: ";
    std::cin >> user_input;

    int mask1 = user_input / 128;
    int mask2 = user_input / 64;
    int mask3 = user_input / 32;
    int mask4 = user_input / 16;
    int mask5 = user_input / 8;
    int mask6 = user_input / 4;
    int mask7 = user_input / 2;
    int mask8 = user_input / 1;
    
    std::cout << (mask1 % 2);
    std::cout << (mask2 % 2);
    std::cout << (mask3 % 2);
    std::cout << (mask4 % 2);
    std::cout << " ";
    std::cout << (mask5 % 2);
    std::cout << (mask6 % 2);
    std::cout << (mask7 % 2);
    std::cout << (mask8 % 2);
    std::cout << "\n";

    return 0;    
}

/* Another implementation is shown below, this is a better implementation since it adds modularity 
#include <iostream>

void printBit(int x, int pow)
{
    std::cout << ((x / pow) % 2);
}

void print8BitBinary(int x)
{
    printBit(x, 128);
    printBit(x, 64);
    printBit(x, 32);
    printBit(x, 16);

    std::cout << ' ';

    printBit(x, 8);
    printBit(x, 4);
    printBit(x, 2);
    printBit(x, 1);
}

int main()
{
    std::cout << "Enter an integer between 0 and 255: ";
    int x{};
    std::cin >> x;

    print8BitBinary(x);

    std::cout << '\n';

    return 0;
}
    */
