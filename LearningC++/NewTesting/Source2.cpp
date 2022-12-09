#include <iostream>
#include <array>

// ISPECTORS 
// Used to view data, but not modify such as counting

// MUTATORS 
// Used to modify data, such as sorting and shuffling 

// FACILITATORS 
// Generates results based on values on data members


bool greater(uint8_t a, uint8_t b) { return a > b; } // works with sort function
void doubleNum(uint8_t& i) { i *= 2; }

int main() 
{
	std::array<uint8_t, 5> arr{2, 452, 12, 42, 58};

	int i{};
	auto t{ std::find(arr.begin(), arr.end(), i) }; // returns pointer to value, if found 
	
	std::sort(arr.begin(), arr.end(), greater);
	std::for_each(arr.begin(), arr.end(), doubleNum); // applies the function to each iteration
}