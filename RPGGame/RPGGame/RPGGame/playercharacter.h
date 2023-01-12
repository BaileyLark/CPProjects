#pragma once
#include <cstdint>
#include "statblock.h"
#include "pointwell.h"
#include <string>
#include "Abilty.h"
#include <vector>
#include <memory>
#include "Buff.h"

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



	std::unique_ptr<PointWell> HP;  
	std::unique_ptr<PointWell> MP;
	std::vector<Ability> Abilities;


	PlayerCharacterDelegate() : StatBlock(0u, 0u) {
		CurrentLevel = 1u;
		CurrentEXP = 0u; 
		EXPToNextLevel = LEVEL2AT;
		HP = std::make_unique<PointWell>(1u, 1u);
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
HP->setMax(BASEHP); \
HP->Increase(BASEHP); \
if (MP){\
	MP->setMax(BASEHP); \
	MP->Increase(BASEHP); \
} \
increaseStats(BASESTR, BASEHP, BASEAGI); \


#define LEVELUP  \
HP->setMax((welltype)((BASEHP / 2.f) + HP->getMax())); \
HP->Increase((welltype)(BASEHP / 2.f)); \
if (MP){\
	MP->setMax((welltype)((BASEMP / 2.f) + MP->getMax())); \
	MP->Increase((welltype)(BASEMP / 2.f)); \
}\
increaseStats((stattype)(BASESTR + 1u / 2.f), (stattype)(BASEINT + 1u / 2.f), (stattype)(BASEAGI + 1u / 2.f)); \


class Cleric : public PlayerCharacterDelegate {
private:
	void LevelUp() override {
		LEVELUP
		if (CurrentLevel == 2) {
			Abilities.emplace_back("Smite", 2u, 1u, ABILITYTARGET::ENEMY, 2, ABILITYSCALER::INT);
		}
	}
public:

	static const welltype BASEHP = static_cast<stattype>(14u);
	static const stattype BASESTR = static_cast<stattype>(3u);
	static const stattype BASEINT = static_cast<stattype>(5u);
	static const stattype BASEAGI = static_cast<stattype>(1);
	static const welltype BASEMP = static_cast<stattype>(10);
	Cleric() : PlayerCharacterDelegate() {
		MP = std::make_unique<PointWell>(BASEMP, BASEMP);
		PCCONSTRUCT
		Abilities.emplace_back("Heal", 2u, 1u, ABILITYTARGET::ALLY, 2, ABILITYSCALER::INT); // more effiecent that push_back
	};
	std::string getClassName() override { return static_cast<std::string>("Cleric"); } 
}; 


class Wizard : public PlayerCharacterDelegate {
private:
	void LevelUp() override {
		LEVELUP
			if (CurrentLevel == 2) {
				Abilities.emplace_back("IceBolt", 3u, 1u, ABILITYTARGET::ENEMY, 6, ABILITYSCALER::INT);
				MP->setMax(1u + HP->getMax());
				MP->Increase(1u); 

				increaseStats(0, 1);
			}
	}
public:

	static const welltype BASEHP = static_cast<stattype>(10u);
	static const stattype BASESTR = static_cast<stattype>(3u);
	static const stattype BASEINT = static_cast<stattype>(1u);
	static const stattype BASEAGI = static_cast<stattype>(8u);
	static const welltype BASEMP = static_cast<stattype>(14u);
	Wizard() : PlayerCharacterDelegate() {
		MP = std::make_unique<PointWell>(BASEMP, BASEMP);
		PCCONSTRUCT
			Abilities.emplace_back("Firebolt", 2u, 1u, ABILITYTARGET::ENEMY, 4u, ABILITYSCALER::INT); // more effiecent that push_back
	};
	std::string getClassName() override { return static_cast<std::string>("Wizard"); }
};

class Warrior : public PlayerCharacterDelegate {
private:
	void LevelUp() override {
		LEVELUP
			if (CurrentLevel == 2) {
				Abilities.emplace_back("Slash", 0u, 3u, ABILITYTARGET::ENEMY, 4u, ABILITYSCALER::STR); ;
			}
	}
public:

	static const welltype BASEHP = static_cast<stattype>(18u);
	static const stattype BASESTR = static_cast<stattype>(6u);
	static const stattype BASEINT = static_cast<stattype>(2u);
	static const stattype BASEAGI = static_cast<stattype>(2u);
	static const welltype BASEMP = static_cast<stattype>(0u);
	Warrior() : PlayerCharacterDelegate() {
		//MP = std::make_unique<PointWell>(BASEMP, BASEMP);
		PCCONSTRUCT
	}
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
	welltype getCurrentHP() { return pcclass->HP->getCurrent(); }
	welltype getMaxHP() { return pcclass->HP->getMax(); }

	welltype getCurrentMP() { 
		if (pcclass->MP)
			return pcclass->MP->getCurrent();
		else
			return 0; }

	welltype getMaxMP() {
		if (pcclass->MP)
			return pcclass->MP->getMax();
		else 
			return 0; }

	stattype getStrength() { return pcclass->getBaseStrength(); }
	stattype getIntellect() { return pcclass->getBaseIntellect(); }
	stattype getAgility() { return pcclass->getBaseAgility(); }
	stattype getElementRes() { return pcclass->getBaseElementRes(); }


	void gainEXP(exptype amt) { pcclass->gainEXP(amt); }
	void takeDamage(welltype amt) { pcclass->HP->Increase(amt); }
	void heal(welltype amt) { pcclass->HP->Reduce(amt); }

	void ApplyBuff(Buff buff){
		pcclass->applyBuff(buff);
	}
};