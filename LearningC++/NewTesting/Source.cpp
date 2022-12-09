#include <iostream>
#include <random>
#include <chrono>
#include <cstring>
#include <string_view>

int test_main()
{
	// RANDOM NUMBERS //

	std::mt19937 mt;  // #include <random>, creates a 32-bit object
	mt(); // generates a random number (actually 'mt.operator()')
	std::uniform_int_distribution<> die6{ 1, 6 }; //generates a number between 1 and 6
	std::random_device{}(); //the brakcets returns a temporary object, dont reseed

	// COERCION //

	// Implict conversion happpens when the compiler does it, explicit when asked. 
	// Floating point promotion when a float converts into double
	// Signed chars convert into int, unsigned char/short convert into int.
	int a{ 5 };
	static_cast<int>(a);
	(double)a; // C-style cast (Avoid)

	// TYPE DEDUCTION // 
	const auto i{ 5.0 }; // compiler knows its a double
	auto i2{ "Hello" }; // results in char*, putting s or sv after the final " resoles into str or strview
   //auto addition() {}
}; // auto can also be put before functions

// FUNCTION OVERLOADING // 
int addition(){} // overloaded function with the same name 
// also checks by converting the parameters 
// if two functions match then cast the parameter
double subtract(int a, int b = 10) {} //default parameter

// FUNCTION TEMPLATE // 
template<typename T> // first tell the compiler it's a template function, then the type parameters
T max(T x, T y){} //define the function but with the parameters instead. 
// they aren't functions 

// l-value is a variable that isn't specificed 'int y = {x}'
// r-value is a variable that are specified
// however, if the return value is temporary it's r-value, so 'int getint(){return 5}' or casting

int i{ 5 };
int& r{ i }; // a reference to another value, allows you to modity the original value, not an object
const int& r2{ i }; // can be bound to non-const value
const int& r3{ 5 }; // bound to a temp object, which has same duration as reference
// can't be bound to l-values such as const or a value, they can't be changed.

void printVal(int& i) {} // doesn't pass a copy, the actual object
void printVal(int* i) {} // pass by address, must be dereferenced using *
void printVal(const int* i) {}

const std::string& var(){} // returns by reference, always has to be const
// if a 'auto' type calls a function that returns a reference(&), the reference is dropped
// if a 'auto' type calls a function that returns a pointer(*), it's kept

// C-STYLE STRINGS 

char string[]{"Hello"}; 
int len{ std::strlen(string) }; // length of a c-style string 
int size{ std::size(string) }; // characters in string 

// STRING_VIEW 

std::string_view sv1{ "hello" }; // stored in binary 
std::string_view sv2{ sv1 }; // a view of sv1, not a copy 
// a string_views lifespan is dependant on what it's viewing

