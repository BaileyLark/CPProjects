#pragma once
#include "hp.h"
#include "statblock.h"
#include "experience.h"

class Cleric : public hp, public StatBlock, public Experience
{
private:
	void LevelUp() override {
		setMaxHP(HPGROWTH + getMaxHp());
		increaseStats(STRGROWTH, INTGROWTH);
	}

public:

	static const hptype BASEHP = static_cast<stattype>(14u); // Static means however many classes, only one variable
	static const stattype BASESTR = static_cast<stattype>(2u);
	static const stattype BASEINT = static_cast<stattype>(3u);

	static const hptype HPGROWTH = static_cast<stattype>(7u); // Static means however many classes, only one variable
	static const stattype STRGROWTH = static_cast<stattype>(1u);
	static const stattype INTGROWTH = static_cast<stattype>(2u);

	Cleric() : hp(BASEHP, BASEHP), StatBlock(BASESTR, BASEINT) {} // Calls the hp constructor

};
