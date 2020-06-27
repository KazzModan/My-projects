#pragma once
#include "Unit.h"
class Archer : public Unit
{
public:
	enum RangeWeapon
	{
		NONE, BOW, COMP_BOW,CROSSBOW, SLINGSHOT
	};
	Archer(size_t weapon = 0, size_t hp = 15, size_t dmg = 5, size_t dodge = 60);
	void setWeapon(size_t weapon);
private:
	RangeWeapon weapon;
};

