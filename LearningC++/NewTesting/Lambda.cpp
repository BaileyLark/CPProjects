#include <iostream>
#include <array>
#include <algorithm>
#include <functional>

// A lambda is an anonymous function

int main()
{
	int a{5};
	int b{};
	const std::array<std::string, 4> arr{ "apple", "banana", "walnut", "lemon" };

	auto found{ std::find_if(arr.begin(), arr.end(),
		[&a, b, c{a+b}](mutable std::string str) {return(str.find("banana") != std::string::npos); }) };
	// the [] captures any variables, the () is the parameters and the {} is the logic
	auto print{ [](auto value) {} }; // each time a new lambda is created

	// use = to capture all variables used in the lambda
	// use & to capture all variables used in the lambda by reference
	// the mutable keyword allows the copy to be modified, can also do '&' to edit the original
	// a capture is a const clone with an identical name, and possibly not the same type
	//std::sort(arr.begin(), arr.end(), std::greater{}); // 
}

bool found(std::string str) {
	return(str.find("banana") != std::string::npos);
}
