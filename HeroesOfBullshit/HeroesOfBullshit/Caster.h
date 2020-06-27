#pragma once
#include "Unit.h"
class Caster : public Unit
{
public:
	enum CasterWeapon
	{
		NONE, WAND, SCEPTRE, SPECTRES, ZOMBIES
	};
	Caster(size_t weapon = 0, size_t hp = 8, size_t dmg = 5, size_t dodge = 60);
	void setWeapon(size_t weapon);
private:
	CasterWeapon weapon;
};

