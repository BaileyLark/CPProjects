#pragma once
#include <cstdint>
#include "statblock.h"
#include "pointwell.h"
#include <string>
#include "Abilty.h"
#include <vector>
typedef std::uint64_t exptype; 
typedef std::uint16_t leveltype;

class PlayerCharacterDelegate : public StatBlock{
protected:
	leveltype CurrentLevel;
	exptype CurrentEXP;
	exptype EXPToNextLevel;

	bool check_if_leveled() {
		static const leveltype EXPSCALE{ 2 };
		if (CurrentEXP >= EXPToNextLevel) {
			CurrentLevel++;
			LevelUp();
			EXPToNextLevel *= EXPSCALE;
			return true;
		}
		return false;
	}
	
public:

	static const exptype LEVEL2AT{ 100u }; 

	leveltype getLevel() { return CurrentLevel; }
	exptype getCurrentEXP() { return CurrentEXP; }
	exptype getEXPToNextLevel() { return EXPToNextLevel; }

	virtual void LevelUp() = 0;
	virtual std::string getClassName() = 0;

	PointWell HP;  
	std::vector<Ability> Abilities;

	PlayerCharacterDelegate() : StatBlock(0u, 0u) {
		CurrentLevel = 1u;
		CurrentEXP = 0u; 
		EXPToNextLevel = LEVEL2AT;
		//HP = (welltype)1;
	}

	void gainEXP(exptype gained_exp) {
		CurrentEXP += gained_exp;
		while (check_if_leveled()){}
	}

};

//#define CHARACTERCLASS(classname, basehp, basestr, baseint, baseagi) \
//class classname : public PlayerCharacterDelegate { \
//private: \
//	LEVELUP; \
//public: \
//	static const welltype BASEHP = static_cast<stattype>(basehp); \
//	static const stattype BASESTR = static_cast<stattype>(basestr); \
//	static const stattype BASEINT = static_cast<stattype>(baseint); \
//	static const stattype BASEAGI = static_cast<stattype>(baseagi); \
//	classname()PCCONSTRUCT \
//	std::string getClassName() override { return static_cast<std::string>(#classname); } \
//}; 

//CHARACTERCLASS(Wizard, 10, 1, 8, 1)
//CHARACTERCLASS(Warrior, 20, 5, 2, 2)
//CHARACTERCLASS(Rouge, 22, 6, 1, 1)

#define PCCONSTRUCT \
HP.setMax(BASEHP); \
HP.Increase(BASEHP); \
increaseStats(BASESTR, BASEHP, BASEAGI) \

#define LEVELUP  \
HP.setMax((welltype)((BASEHP / 2.f) + HP.getMax())); \
HP.Increase((welltype)(BASEHP / 2.f)); \
increaseStats((stattype)(BASESTR + 1u / 2.f), (stattype)(BASEINT + 1u / 2.f), (stattype)(BASEAGI + 1u / 2.f)); \


class Cleric : public PlayerCharacterDelegate {
private:
	void LevelUp() override {
		LEVELUP
		MP.setMax((welltype)((BASEHP / 2.f) + MP.getMax()));
		MP.Increase((welltype)(BASEHP / 2.f));
		if (CurrentLevel == 2) {

		}

	}
public:
	static const welltype BASEHP = static_cast<stattype>(14u);
	static const stattype BASESTR = static_cast<stattype>(3u);
	static const stattype BASEINT = static_cast<stattype>(5u);
	static const stattype BASEAGI = static_cast<stattype>(1);
	static const welltype BASEMP = static_cast<stattype>(10);
	Cleric() : PlayerCharacterDelegate() {
		PCCONSTRUCT;
		MP.setMax(BASEHP); 
		MP.Increase(BASEHP); 
		Abilities.emplace_back("Heal", 2u, 1u, ABILITYTARGET::ALLY, 2, ABILITYSCALER::INT); // more effiecent that push_back
	};

	PointWell MP;
	

	std::string getClassName() override { return static_cast<std::string>("Cleric"); } 
}; 



class PlayerCharacter {
private:
	PlayerCharacterDelegate* pcclass;
public:
	PlayerCharacter() = delete;
	PlayerCharacter(PlayerCharacterDelegate* pc) : pcclass(pc) {};
	~PlayerCharacter() { delete pcclass; pcclass = nullptr; }

	//testing 

	std::vector<Ability> getAbilityList(){ return pcclass->Abilities; }

	std::string getClassName() { return pcclass->getClassName(); }
	leveltype getLevel() { return pcclass->getLevel(); }
	exptype getCurrentEXP() { return pcclass->getCurrentEXP(); }
	exptype getEXPtoNextLevel() { return pcclass->getEXPToNextLevel(); }
	welltype getCurrent() { return pcclass->HP.getCurrent(); }
	welltype getMax() { return pcclass->HP.getMax(); }
	stattype getStrength() { return pcclass->getStrength(); }
	stattype getIntellect() { return pcclass->getIntellect(); }
	stattype getAgility() { return pcclass->getAgility(); }
	stattype getElementRes() { return pcclass->getElementRes(); }


	void gainEXP(exptype amt) { pcclass->gainEXP(amt); }
	void takeDamage(welltype amt) { pcclass->HP.Increase(amt); }
	void heal(welltype amt) { pcclass->HP.Reduce(amt); }
};