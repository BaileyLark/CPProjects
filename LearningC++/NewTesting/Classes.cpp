#include <iostream>
#include <string>

class Date // start classes with capital letters
{
private: // all information outside public is by default private
	std::string planet{ "Earth" };
	const int moons{};

public:
	using AD = bool;
	int day{};
	int month{};
	int year{};
	AD type{ true };

	// constructors do not create objects, they allocate memory=
	Date() = default;
	Date(int d, int m, int y, int mo) : day{ d }, month{ m }, year{ y }, moons{ mo }{} // Initalizer list
	Date() { day = 0, month = 0, month = 0; } // default constructor
	Date(int day, int month) { year = 0; } // if the year is omitted

	void print(bool a) { std::cout << "The date is" << print(); };
	std::string print() { return std::to_string(year); }; // getter
	std::string& getPlanet(){ return planet;} 
	Date& addYear(int value) { day =+ value; return *this; } // returns Date so it can be 
	Date& addMonth(int value) { month = +value; return *this; }
	// a function call be called before the complier knows it exists
	void setPlanet(std::string p) { planet = p; } // setter *this is a pointer (this->planet = 12)
	// members can access private data
	friend class System; // gives functions access to private data members
	// class members can also be friends using friend System::reset(&System sys);
};

class System // classes can be made const 
{
private:
	int radiation{};
	std::string biomes[3];
	float Matrix[4][4]{};
	static const int universe = 0;
public:
	std::string& getBiome(); // foward declaration for getBiome
	System() : biomes{ "taiga", "desert", "temperate" } {} // intialisting an array

	void reset() { *this = System{}; } // reset the class by calling the default
	std::string& getBiome() { return *biomes; } // can only be called by const objects
	static int getUni() { return universe; }

	friend void resetSystem(System& sys); // a friend delcaration allows functions to access private data 
	friend std::ostream operator<<(std::ostream out, const System& Sys); // overloading the << operator
	// OVERLOADING // 
	
	System& operator++(); // prefix ++i
	System& operator++(int); // postfix i++
	std::string& operator[](int); // overloading subscript to access the array
	float& operator()(int row, int col); // overloading () to allow matricies '[][]'
	float operator()(int row, int col) const; // works with const matricies '[][]'
	void operator()(); // allows to call classinstance(), then have it do something

};

std::ostream operator<<(std::ostream out, const System& Sys) // overloading with friend function 
{
	out << Sys.biomes << Sys.radiation; 
}

// OVERLOADS // 

std::string& System::operator[](int index) { return biomes[index]; } // [] overloading, 
// allows you to type classname[0], and have it return the amount
System& System::operator++() { if (radiation < 999) ++radiation; else return *this; } 
System& System::operator++(int) { if (radiation < 999) ++radiation; else return *this; }
// overloading the operator++, the return *this means they can be chained together
float& System::operator()(int row, int col) { return Matrix[row][col]; }
// overloading the (), a declaration must first be placed in the class, must also be a member function
float System::operator()(int row, int col) const { return Matrix[row][col]; }
// overloading the () for a const matricie [][]
void System::operator()() { ; }
void resetSystem(System& sys) { sys.radiation = 0; }; // a function that changes private data
// MUST HAVE FRIEND DECLARATION


std::string& System::getBiome() { return *biomes; } // functiom member outside the class


// OVERLOADING TYPECASTS

class Vehicle
{
private:
	std::string make;
	std::string model; 
	int horsepower;

public:
	Vehicle(std::string _make, std::string _model, int _horsepower) : make{ _make }, model{ _model }, horsepower{ _horsepower } {}
	operator std::string() const { return make; } // allows to pass the class as an int, as wall as static_cast<int>
};






int test_main()
{
	Vehicle Ferrari{ "Ferrari", "F430", 550 };
	Date today{}; // create object, calls default constructor
	today.month = { 12 }; // sets item to 12,
	today.print(); // calls print 
	today.getPlanet() = "mars"; // returns the memory address so it can be changed
	today.addYear(5).addMonth(4); // works as the functions return 
	

	const System Solar{}; // a const class, can only call const functions 
	System::getUni(); // static functions can be directly accessed without creating an object 
}; 

