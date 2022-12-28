#pragma once
#include <cstdint>
typedef uint32_t welltype;

class PointWell {
private:
	welltype Current;
	welltype Max;

public:
	PointWell() { Current = 1; Max = 1; }

	PointWell(welltype c, welltype m) {
		Current = c;
		Max = m;
		if (Current > Max)
			Current = Max;
	}

	welltype getMax() { return Max; }
	welltype getCurrent() { return Current; }

	// SET MAX 
	bool setMax(welltype new_max) {
		if (new_max < 1)
			return false;

		Max = new_max;


		if (Current > Max)
			Current = Max;

		return true;
	}

	// DAMAGE
	bool Reduce(welltype damage) {
		if (damage > Current) {
			Current = 0;
		}

		Current -= damage;
	}

	// HEALING
	void Increase(welltype amount) {
		if (amount + Current > Max) {
			Current = Max;
			return;
		}

		Current += amount;
	}
};