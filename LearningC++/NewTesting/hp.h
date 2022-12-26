#pragma once
#include "hitpointtypes.h"

class hp{
private:
	hptype CurrentHP;
	hptype MaxHP;
	hptype ShieldHP;

public:

	hptype getMaxHp() { return MaxHP; }
	hptype getCurrentHP() { return CurrentHP; }
	hptype getShieldHP() { return ShieldHP; }

	// SET MAX HP
	bool setMaxHP(hptype new_max_hp) {
		if (new_max_hp < 1)
			return false;

		MaxHP = new_max_hp;


		if (CurrentHP > MaxHP)
			CurrentHP = MaxHP;

		return true;
	}

		// DAMAGE
	bool takeDamage(hptype damage) {
		if (damage > CurrentHP) {
			CurrentHP = 0;
			return;
		}

		CurrentHP -= damage;
	}

	// HEALING
	void heal(hptype amount) {
		if (amount + CurrentHP > MaxHP) {
			CurrentHP = MaxHP; 
			return; 
		}
		
		CurrentHP += amount; 
	}

};