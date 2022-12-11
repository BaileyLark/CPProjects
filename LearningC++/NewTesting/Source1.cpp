// STATIC MEMORY ALLOCATION 
// for static and global variabls. Memory is allocated when the program is run and persists

// AUTOMATIC MEMORY ALLOCATION
// for function paramaters and local variables. When the block is entered the memory is allocated
// once it's exited, it's given back

// DYNAMIC MEMORY ALLOCATION
// Most normal values are allocated on the heap, which is gigabytes.

#include <iostream>
#include <array>
#include <algorithm>
#include <vector>


int main(int argc, char* argv[]) // argc is the amount of command lines, argv[] is the arguments
{
	new int; // dynamically allocates an integer, returns a pointer 
	int* ptr{ new int{ 5 } }; // holds the memory address of the new int 
	int** ptr2{ &ptr }; // pointer to a pointer  
	std::cout << *ptr; // dereferences then prints 5 
	delete ptr; // returns the memory back 
	ptr = nullptr; // set the pointer to nothing 

	const int a{ 5 };
	int* arptr{ new int[a] {12, 12, 31, 21} }; // the size doesn't have to be defined
	//int** arptr2{ new int[10]{} }; // a pointer that points to an array that decays into pointer
	arptr[0] = 5;
	delete[] arptr; // delete an array object

	void* ptr{}; // a void pointer can point to any object, cannot be dereferenced
	std::cout << (static_cast<int*>(ptr)); // however, it can be cast then printed

	// ARRAY // 
	std::array<int, 3> arr{ 3, 2, 1 }; // doesn't decay into pointer
	for (const int i : arr) {}
	std::sort(arr.begin(), arr.end());
	arr[3] = 5; // doesn't check if valid
	arr.at(1) = 5;  // checks if valid but slower 
	arr.size(); // returns length of array 

	// FUNCTION POINTERS // 
	int (*fnctPtr)() {&fnct}; // points to fnct function 
	(*fnctPtr)();
	fnctPtr(); // also calls fnct


	// ARRAY LIST, DOESN'T WORK
	//std::array<uint8_t, 3> ar3{
	//	{
	//		{12, 214, 42},
	//		{23, 21, 34},
	//		{12, 53, 63},
	//	}
	//};

	// VECTOR // 
	// Handles own memory memory management 
	std::vector<uint8_t> vect1{ 2, 4, 213, 1, 2, 12 };
	std::vector<bool>{true, false, true, false};
	vect1[0];
	vect1.at(0); 
	vect1.resize(3);

	int* array{ new int[10]{1,2,3,4,5} };
	vect1.resize(5);
	// despite a length of 10, 5 elements are not used. Capacity is total, length is used. 
	vect1.capacity();

}


void arrfunct(const std::array<int, 3>& a) {} // pass arrays by const reference
int fnct() {};

// ANONYMOUS OBJECTS // 
int add(int a, int b) { return a + b; } // a+b is an anonymous object 
int a{ add(5 + 3, 5) }; // anonymous object  

// RECURSION // 
void count(int counter) { count(counter - 1); }

// STACK AND HEAP // 

// code segment is where the complied programs sits in memory and is read only 
// BBS segment is where zero-initalised global and static variales are stored
// Data segment is where initialised global and static variables are stroed
// The heap is where dynamically allocated variables are stroed 
// The call stack is where function paramters, local variables and other function informat are stored

