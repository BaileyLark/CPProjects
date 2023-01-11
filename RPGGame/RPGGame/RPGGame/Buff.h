#pragma once
#include <cstdint>
#include "StatBlock.h"
#include <string>

struct Buff {

	Buff(std::string name = "unnamed", uint16_t dur = 2u,
		stattype str = 1, stattype intel = 1, stattype agi = 1,
		stattype arm = 0u, stattype eleres = 0u, bool isdebuff = false)
		: Name(name), Duration(dur), Strength(str), Intellect(intel), 
		Agility(agi), Armour(arm), ElementRes(eleres)
	{}

	bool isDebuff;
	std::string Name;
	uint16_t Duration;

	stattype Strength;
	stattype Intellect;
	stattype Agility;
	stattype Armour;
	stattype ElementRes;
};
