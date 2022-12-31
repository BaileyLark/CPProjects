#pragma once
#include <string>
#include <cstdint>

enum class ABILITYTARGET { SELF, ALLY , ENEMY };
enum class ABILITYSCALER { NONE, STR, AGI, INT };

struct Ability {
	Ability(std::string name, uint32_t cost, uint32_t cd, ABILITYTARGET t, uint32_t hpe, ABILITYSCALER as) : 
		Name(name), Cost(cost), Cooldown(cd), Target(t), Hp_effect(hpe), Scaler(as){}

	std::string Name = "unnamed";
	uint32_t Cost = 0; // assume mp if cost 
	uint32_t Cooldown = 1; // rounds to wait
	ABILITYTARGET Target = ABILITYTARGET::SELF; 
	ABILITYSCALER Scaler = ABILITYSCALER::NONE;
	uint32_t Hp_effect = 1;
};

