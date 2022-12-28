#pragma once
#include <cstdint>
#include "statblock.h"
#include "pointwell.h"
#include <memory>
#include <string>
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

	PlayerCharacterDelegate() : StatBlock(0u, 0u) {
		CurrentLevel = 1u;
		CurrentEXP = 0u; 
		EXPToNextLevel = LEVEL2AT;
		HP = std::make_unique<PointWell>();
	}

	void gainEXP(exptype gained_exp) {
		CurrentEXP += gained_exp;
		while (check_if_leveled()){}
	}

};

#define PCCONSTRUCT : PlayerCharacterDelegate() { \
HP->setMax(BASEHP); \
HP->Increase(BASEHP); \
increaseStats(BASESTR, BASEHP); \
}

#define LEVELUP void LevelUp() override { \
HP->setMax((welltype)((BASEHP / 2.f) + HP->getMax())); \
HP->Increase((welltype)(BASEHP / 2.f)); \
increaseStats((stattype)(BASESTR + 1u / 2.f), (stattype)(BASESTR / 2.f)); \
}



class Cleric : public PlayerCharacterDelegate
{
private:
	LEVELUP;

public:

	static const welltype BASEHP = static_cast<stattype>(14u); // Static means however many classes, only one variable
	static const stattype BASESTR = static_cast<stattype>(2u);
	static const stattype BASEINT = static_cast<stattype>(3u);

	Cleric()PCCONSTRUCT
	std::string getClassName() override { return std::string("Cleric"); }

};

class Rouge : public PlayerCharacterDelegate
{
private:
	LEVELUP;
public:

	static const welltype BASEHP = static_cast<stattype>(12u); // Static means however many classes, only one variable
	static const stattype BASESTR = static_cast<stattype>(3u);
	static const stattype BASEINT = static_cast<stattype>(2u);

	Rouge()PCCONSTRUCT
	std::string getClassName() override { return std::string("Cleric"); }

};

class Warrior : public PlayerCharacterDelegate
{
private:
	LEVELUP;
public:

	static const welltype BASEHP = static_cast<stattype>(18u); // Static means however many classes, only one variable
	static const stattype BASESTR = static_cast<stattype>(4u);
	static const stattype BASEINT = static_cast<stattype>(1u);

	Warrior()PCCONSTRUCT

	std::string getClassName() override { return std::string("Cleric"); }

};

class Wizard : public PlayerCharacterDelegate
{
private:
	LEVELUP;

public:

	static const welltype BASEHP = static_cast<stattype>(10u); // Static means however many classes, only one variable
	static const stattype BASESTR = static_cast<stattype>(1u);
	static const stattype BASEINT = static_cast<stattype>(4u);

	Wizard()PCCONSTRUCT

	std::string getClassName() override { return std::string("Cleric"); }

};

class PlayerCharacter {
private:
	PlayerCharacterDelegate* pcclass;
public:
	PlayerCharacter() = delete;
	PlayerCharacter(PlayerCharacterDelegate* pc) : pcclass(pc) {};
	~PlayerCharacter() { delete pcclass; pcclass = nullptr; }

	std::string getClassName() { return pcclass->getClassName(); }
	leveltype getLevel() { return pcclass->getLevel(); }
	exptype getCurrentEXP() { return pcclass->getCurrentEXP(); }
	exptype getEXPtoNextLevel() { return pcclass->getEXPToNextLevel(); }
	welltype getCurrent() { return pcclass->HP->getCurrent(); }
	welltype getMax() { return pcclass->HP->getMax(); }
	stattype getStrength() { return pcclass->getStrength(); }
	stattype getIntellect() { return pcclass->getIntellect(); }

	void gainEXP(exptype amt) { pcclass->gainEXP(amt); }
	void takeDamage(welltype amt) { pcclass->HP->Increase(amt); }
	void heal(welltype amt) { pcclass->HP->Reduce(amt); }
};