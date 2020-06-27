#include "Caster.h"
Caster::Caster(size_t weapon = 0, size_t hp = 15, size_t dmg = 5, size_t dodge = 60) : Unit(hp, dmg, dodge, type)
{
	setType(MAGE);
	setWeapon(weapon);
	setHp(hp);
	setDodge(dodge);
	setDmg(dmg);
}

void Caster::setWeapon(size_t weapon)
{
	switch (weapon)
	{
	case 0:
		this->weapon = NONE;
		break;
	case 1:
		this->weapon = WAND;
		break;
	case 2:
		this->weapon = SCEPTRE;
		break;
	case 3:
		this->weapon = SPECTRES;
		break;
	case 4:
		this->weapon = ZOMBIES;
		break;
	default:
		break;
	}
}

