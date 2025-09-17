#include <bitset>
#include <iostream>

// "rotl" stands for "rotate left"
std::bitset<4> rotl(std::bitset<4> bits)
{
    std::bitset<4> left_shifted_bits = bits << 1; // This is simply a left-shift of bits

    std::bitset<4> right_shifted_bits_3 = bits >> 3; // This is a right shift of bits of 3 positions
    // This carries the leftmost bit to the position of the rightmost bit, this account for cases where
    // the leftmost bit is a bit value of 1 (true)

    std::bitset<4> new_bits = left_shifted_bits | right_shifted_bits_3; 

    return new_bits;
}

int main()
{
	std::bitset<4> bits1{ 0b0001 };
	std::cout << rotl(bits1) << '\n';

	std::bitset<4> bits2{ 0b1001 };
	std::cout << rotl(bits2) << '\n';

	return 0;
}
