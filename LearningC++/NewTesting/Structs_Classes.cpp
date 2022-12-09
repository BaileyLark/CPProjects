#include <iostream>
#include <iterator>

using namespace std;

struct Birthday
{
	uint8_t day{};
	uint8_t month{};
	uint8_t year{ 0 }; // non static member initializaton, default value
};

// the size of a struct is the variable sizes + 2, as padding

int test_main()
{
	// STRUCTS 
	Birthday Max{}; // creates a empty struct object
	Birthday Joe{ 16, 5 }; // sets day an month to respective values, year is 0
	const Birthday Alex{ 15, 5, 2004 };
	Max.day = 15; // to set a single value
	Max = { 15, 5, 2001 }; // sets muliple values at once 
	Birthday* pjoe{ &Joe }; // A pointer to Joe

	cout << (*pjoe).day; // acces the pointers value
	cout << pjoe->day;  // dereference the pointer to access its value 

	// ARRAYS
	uint16_t score[5]{5, 3, 2, 43}; // [5] element is set to 0
	uint16_t scores[]{ 4, 3, 42 ,1 }; // The compiler auto assigs the length
 
	std::cout << &score + 1; // prints memory address of [1]

	std:size(score); // length of the array 
	// when an array is used in an expression it decays to a point to [0] in the array


	int scoreladder[3][5] // multidimensional array 
	{
	  { 1, 2, 3, 4, 5 }, // row 0
	  { 6, 7, 8, 9, 10 }, // row 1
	  { 11, 12, 13, 14, 15 } // row 2
	};

	for (int student{0}; student < static_cast<int>(std::size(score)); ++student){}
	
}

void struct_funct(const Birthday& birthday) {} // structs are passed by reference
void array_funct(uint16_t score[5]) {} // When passed into a function the array isn't copied, the [] is interpreted as pointer




