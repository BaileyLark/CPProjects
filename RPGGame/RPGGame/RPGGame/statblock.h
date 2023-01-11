#pragma once
#include <cstdint>
#include <Buff.h>
typedef std::uint16_t stattype;

class StatBlock {
private:
	stattype Strength;
	stattype Intellect;
	stattype Agility;
	stattype Armour;
	stattype ElementRes;

public:

	stattype getStrength() { return Strength; }
	stattype getIntellect() { return Intellect; }
	stattype getAgility() { return Agility; }
	stattype getArmour() { return Armour; }
	stattype getElementRes() { return ElementRes; }

	std::vector<Buff> Buffs;
	std::vector<Buff> DeBuffs;
	//void setStrength(stattype s) { Strength = s; }

	StatBlock() { 
		Strength = (stattype)0u; 
		Intellect = (stattype)0u; 
		Armour = (stattype)0u;
		ElementRes = (stattype)0u;
		Agility = (stattype)0u;
	}

	// wont allow type conversion 
	explicit StatBlock(stattype s = 1, stattype i = 1, stattype a = 1, stattype arm = 0u, stattype eleres = 0u) {
		Strength = s;
		Intellect = i;
		Agility = a;
		Armour = arm;
		ElementRes = eleres;
	}

protected: 
	void increaseStats(stattype s=0, stattype i=0, stattype a=0, stattype arm=0, stattype eleres =0) {
		Strength += s;
		Intellect += i;
		Agility += a;
		ElementRes += eleres; 
		Armour += arm; 
	}
};