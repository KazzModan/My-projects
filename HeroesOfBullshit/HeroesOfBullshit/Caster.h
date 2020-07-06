#pragma once
#include "Unit.h"
#include <iostream>
using namespace std;
class Caster : public Unit
{
public:
	enum CasterWeapon
	{
		NONE, WAND, SCEPTRE, SPECTRES, ZOMBIES
	};
	Caster(size_t weapon = 0, size_t hp = 8, size_t dmg = 10, size_t dodge = 30);
	void setWeapon(size_t weapon);
	void print();
private:
	CasterWeapon weapon;
};

