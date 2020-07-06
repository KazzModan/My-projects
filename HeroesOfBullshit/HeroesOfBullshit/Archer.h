#pragma once
#include "Unit.h"
#include <iostream>
using namespace std;

class Archer : public Unit
{
public:
	enum RangeWeapon
	{
		NONE, BOW, COMP_BOW,CROSSBOW, SLINGSHOT
	};
	Archer(size_t weapon = 0, size_t hp = 12, size_t dmg = 4, size_t dodge = 40);
	void setWeapon(size_t weapon);
	void print();
private:
	RangeWeapon weapon;
};

