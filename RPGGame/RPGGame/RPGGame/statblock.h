#pragma once
#include <cstdint>
#include "Buff.h"

typedef std::uint16_t stattype;

class StatBlock {
private:
	stattype BaseStrength;
	stattype BaseIntellect;
	stattype BaseAgility;
	stattype BaseArmor;
	stattype BaseElementRes;

	stattype TotalStrengthFromBuffs = 0;
	stattype TotalIntellectFromBuffs = 0;
	stattype TotalAgilityFromBuffs = 0;
	stattype TotalArmourFromBuffs = 0;
	stattype TotalElementResFromBuffs = 0;

public:

	stattype getBaseStrength() { return BaseStrength; }
	stattype getBaseIntellect() { return BaseIntellect; }
	stattype getBaseAgility() { return BaseAgility; }
	stattype getBaseArmour() { return BaseArmor; }
	stattype getBaseElementRes() { return BaseElementRes; }

	stattype getTotalStrength() { return BaseStrength + TotalStrengthFromBuffs; }
	stattype getTotalIntellect() { return BaseIntellect + TotalIntellectFromBuffs;  }
	stattype getTotalAgility() { return BaseAgility + TotalAgilityFromBuffs; }
	stattype getTotalArmour() { return BaseArmor + TotalArmourFromBuffs; }
	stattype getTotalElementRes() { return BaseElementRes; }


	//void setStrength(stattype s) { BaseStrength = s; }

	StatBlock() { 
		BaseStrength = (stattype)0u; 
		BaseIntellect = (stattype)0u; 
		BaseArmor = (stattype)0u;
		BaseElementRes = (stattype)0u;
		BaseAgility = (stattype)0u;
	}

	// wont allow type conversion 
	explicit StatBlock(stattype s = 1, stattype i = 1, stattype a = 1, stattype arm = 0u, stattype eleres = 0u) {
		BaseStrength = s;
		BaseIntellect = i;
		BaseAgility = a;
		BaseArmor = arm;
		BaseElementRes = eleres;
	}

protected: 
	void increaseStats(stattype s=0, stattype i=0, stattype a=0, stattype arm=0, stattype eleres =0) {
		BaseStrength += s;
		BaseIntellect += i;
		BaseAgility += a;
		BaseElementRes += eleres; 
		BaseArmor += arm; 
	}
	
	void AddNewBuff(Buff b) {
		for (auto& buff : Buffs) {
			if (b.Name == buff.Name) {
				buff.Duration = b.Duration;
				return;
			}
		}
		Buffs.push_back(b);
		recalculate_buffs();
	}

	std::vector<Buff> Buffs;
private:
	void recalculate_buffs() {

	}
};