#include <iostream>

//	NAMESPACES //

namespace prints //defines a namespace
{ 
	void hello() //called with prints::hello() ::hello will ignore namespace and look in global
	{
		std::cout << "Hello";
	}


	namespace greetings{}
	//if a ::hello is called inside the namespace it first looks in the 
	//namespace, then globally. 
	//multple namespace can be used such as strs::prints::hello()
	//different files can have the same namespace, but include #include 'file.h'

	namespace hey = prints::greetings; //a namespace alias
	namespace {}; //an unnamed namespace forced its content to have internal linkage
	inline namespace {}; //allows multiple functions of the same name
	//consteval only happens during compile time, can't be called.

	typedef double Length; // old way of using type aliases


	enum Colors : std::int16_t // define the enum type
	{
		red, // automatically assigned 0
		green = -5, // you can compare enums together, since they are just int types
		blue = -4,
		orange,
		purple,
	};

	enum class Cars : std::uint16_t // the scope prevents == being used
	{
		Mercedes, 
		Ferrari, 
		Nissan,
	};

	Colors shirt{ red };
	Colors shirt2{ static_cast<Colors>(green) }; // sets shirt2 to -5. Green can also be an int
	Cars Garage{ Cars::Ferrari }; // a class must have the :: to access
}

// TYPE ALIASES // 
 
using Distance = double //allows to use Distance istead of double , not new types just identifiers 
// If it ends in _t, is often used by standard library 
// Start all type Aliases with a capital letter


// DURATION // 

const int g_u1{ 4 }; //global variable, visible till end of file aka static duration or static variables
// avoid nonconst static variables 

constexpr int funct1() // a constexpr function will execute during compile time
{
	int i{ 0 }; // automatic scope duration, it's destroyed at the end of the brackets
	{
		int i{ 0 }; //a nested variable of the same name shadows the outer one (AVOID)
	}
	int g_u1{ 5 }; //use ::g_u1 to access global variable instead
}


// STATIC&LINKAGE VARIABLE // 

// Can only ever be accessed in the global space of a single file, this works with functions too
static int i{}; //Changing a local variable to static retains its value after it goes out of scope

// Both const and constexpr global variables have internal linkage, therfore don't need static. 

// For functions/variables from other files to work they must have a foward delcalation 
extern const int g_i2{}; //use extern on const/constexpr since they only have internal linkage
//variables are global variables by default. 

//To access header files do (#include "name.h")

//If multiple files are using this variable from a header, instead of multiple defintions for each file, it creates one.
//inline constexpr double i3{};
// 


int test_main()
{
	int x{ 5 };
	if (x > 5)     //IF else, statement
		std::cout << "Hello" << std::endl;
	else
		std::cout << "GoodBye" << std::endl;
}
