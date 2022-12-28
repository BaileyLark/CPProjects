#pragma once
#include <cstdint>
typedef std::uint16_t stattype;

class StatBlock {
private:
	stattype Strength;
	stattype Intellect;

public:

	stattype getStrength() { return Strength; }
	stattype getIntellect() { return Intellect; }

	//void setStrength(stattype s) { Strength = s; }

	StatBlock() { 
		Strength = (stattype)0u; 
		Intellect = (stattype)0u; 
	}
	// wont allow type conversion 
	explicit StatBlock(stattype s, stattype i) { 
		Strength = s;
		Intellect = i;
	}

protected: 
	void increaseStats(stattype s, stattype i) {
		Strength += s;
		Intellect += i;
	}
};