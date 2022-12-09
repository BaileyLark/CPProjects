#include <iostream>

const int a = 3;

int test_main() 
{
	// IF STATEMENTS //

		if (a > 5 || a == 15) // use || OR operator, && AND operator
			std::cout << "Higher";
		else if (a > 10)
			std::cout << "Lower";
		else if (a < 0)
			; //a null statemement
		else
			std::cout << "Bigger than 5, smaller than 10";

	// SWITCH STATEMENTS // 

		switch (a)
		{
			case 1: //A case label, (if a == 1)
				return; // a break or return will prevent the rest from executing
			case 2:
				[[fallthrough]]; //if you want the code to continue without raising an error
			default:
				return;
		}

	// GOTO STATEMENTS // (DONT USE)

		statementName: // these must appear in the same function 
		goto statementName; 

	// WHILE STATEMENT //
		while (true);
		//while (;;); old infinite loop

	// DO WHILE STATEMENT // 
		do
		{} while(true);
		// A constant loop until while is satisfied. 

	// FOR STATEMENT // 
		// for(init-statement; condition; end-expression)
		for (int i{0}; i > 10; --i){} // Don't use != 
		for (int i2{ 0 }, int i3{0}; i2 < 10; ++i2, --i3){} //multiple statements

	// BREAK & CONTINUE // 
		while (true) { break; }  // causes a loop to end 
		while (true) { return; } // ends an entire function 
		while (true) { continue; } //goes to the next iteration
		// don't use in loops 

	// FOR EACH 

		int arr[]{ 12, 12, 41, 45, 19 };
		for(const int& i : arr){}
		//for (int i{ 0 }; const int& i : arr) {}) CS20

	// HALTS // (DONT USE)
		std::exit(0); //called when main ends 
		std::atexit(0); //calls std::exit and 0 can be replaced with a function
		std::abort(); //abnormal exit

	// ASSERTION // 
		#include <cassert>
		assert(a == 5 && "Message"); //assert must be true otherwise an error is raised
		static_assert(sizeof(int) == 4, "Message") //checks at compile time, causing compiler error
}



