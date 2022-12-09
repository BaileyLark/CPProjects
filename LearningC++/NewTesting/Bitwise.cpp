#include <iostream>
#include <string>
#include <bitset>

//test, flip, reset, set() functions
//<< shift to left (write it  x >>= y)
//>> shift to right (write it  x <<= y)
//~ all flipped (put it before varible '~std::bitset<8>...')
// & each bit in each ((std::bitset<8>... & std::bitset<8>...))
// | each bit in or ((std::bitset<8>... | std::bitset<8>...))
// compound expressions also work, multiple ||| or &&&
// ^ each bit in xor ((std::bitset<8>... ^ std::bitset<8>...))

// define bitset 
std::bitset<8> i1{ 0101'1010 }; //0b or 0x is optional, so is '.
// define bitmask 
constexpr uint8_t mask{ 0b0000'0010 }; //tests if bit two is on/off
constexpr uint8_t mask2{ 1 << 5 };  //is equal to 0010'0000

// to test a bit use &, such as: (flags | mask) ? "yes\n" : "no\n")
// to set a bit use |=, such as: flags |= mask, or multiple bits with: flags |= (mask | mask2)
// to reset a bit use: flags &= ~mask;
// toggle a state use flags ^= mask; or multiple bits with: flags ^= (mask | mask2)


int test_main()
{
	std::bitset<8> hi {0b0101'1010};
}
