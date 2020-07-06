#pragma once
#include "Unit.h"
#include <iostream>
using namespace std;
class Barbar : public Unit
{
public:
	enum MeeleWeapon
	{
		NONE, AXE, MACE, SWORD, HAMMER
	};
	Barbar(size_t weapon=0, size_t hp=15, size_t dmg=5, size_t dodge=60);
	void setWeapon(size_t weapon);
	void print();
private:
	MeeleWeapon weapon;
};

