#pragma once 
#include <iostream>
#include "playercharacter.h"

int main() {
	
	PlayerCharacter p1(new Cleric());

	for (int i = 0; i < 3; i++) {
		std::cout << p1.getClassName() 
		<< " lvl." << p1.getLevel() 
		<< "(" << p1.getCurrentEXP() << "/" << p1.getEXPtoNextLevel() << ")" << "\n"
		<< "MaxHP: " << p1.getMaxHP() << "\n"
		<< "Strength: " << p1.getStrength() << "\n"
		<< "Intellect: " << p1.getIntellect() << "\n";

		p1.gainEXP(100);

		auto Abilities = p1.getAbilityList();

		std::cout << "Abilities: \n";
		for (auto& abi : Abilities)
			std::cout << "-" << abi.Name << std::endl;
	}
}