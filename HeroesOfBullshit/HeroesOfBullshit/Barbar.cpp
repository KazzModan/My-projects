#include "Barbar.h"

Barbar::Barbar(size_t weapon = 0,size_t hp = 15, size_t dmg = 5, size_t dodge = 60) :Unit(hp, dmg, dodge, type)
{
	setType(BARBAR);
	setWeapon(weapon);
	setHp(hp);
	setDodge(dodge);
	setDmg(dmg);
}

void Barbar::setWeapon(size_t weapon)
{
	switch (weapon)
	{
	case 0:
		this->weapon = NONE;
		break;
	case 1:
		this->weapon = AXE;
		break;
	case 2:
		this->weapon = MACE;
		break;
	case 3:
		this->weapon = SWORD;
		break;
	case 4:
		this->weapon = HAMMER;
		break;
	default:
		break;
	}
}
