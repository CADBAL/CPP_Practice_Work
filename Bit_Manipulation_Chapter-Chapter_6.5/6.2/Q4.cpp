#include <bitset>
#include <iostream>

// "rotl" stands for "rotate left"
std::bitset<4> rotl(std::bitset<4> bits)
{
    // An idea I have is right-shift the variable 'bits' 3 indices right. This will place the left-most bit
    // in the index position of the right-most bit. This new bitset then will be stored as a new variable
    // named right_shift_3_bits. Then i will left-shift bits by one. 
    // I will then compare the new 'bits' variable with  right_shift_3_bits using bitwise OR.
    // The outcome of this bitwise OR operation will be stored in a new variable named rotl_bits. 
    // If the right-most bit (least significant bit) has the value 1 this means the left-most bit of the 
    // original variable 'bits' had a bit value of 1 and was added back to the other end.
    // 1 1 1 0 = OG
    // 1 1 0 0 = NEW after left shift bit
    // A method i am thinking is shift 3 right.
    // 0 0 0 1 

    // 1 1 0 0 OR
    // 0 0 0 1
    // = 1 1 0 1
    
    std::bitset<4> right_shift_3_bits = bits >> 3;

    bits <<= 1;

    std::bitset<4> rotl_bits = right_shift_3_bits | bits;

    return rotl_bits;


}

int main()
{
	std::bitset<4> bits1{ 0b0001 };
	std::cout << rotl(bits1) << '\n';

	std::bitset<4> bits2{ 0b1001 };
	std::cout << rotl(bits2) << '\n';

	return 0;
}

