#include <iostream>
#include <array>
#include <typeinfo>

int main()
{
	std::array<uint8_t, 5> arr{ 2, 452, 12, 42, 58 };
	int i{};
    auto t{ std::find(arr.begin(), arr.end(), 12) };
	std::cout << static_cast<int>(*t) << std::endl;
}