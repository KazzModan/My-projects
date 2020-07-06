#include "Archer.h"
Archer::Archer(size_t weapon = 0,size_t hp = 15, size_t dmg = 5, size_t dodge = 60) : Unit(hp, dmg, dodge, type)
{
	setType(ARCHER);
	setWeapon(weapon);
	setHp(hp);
	setDodge(dodge);
	setDmg(dmg);
}

void Archer::setWeapon(size_t weapon)
{
	switch (weapon)
	{
	case 0:
		this->weapon = NONE;
		break;
	case 1:
		this->weapon = BOW;
		break;
	case 2:
		this->weapon = COMP_BOW;
		break;
	case 3:
		this->weapon = CROSSBOW;
		break;
	case 4:
		this->weapon = SLINGSHOT;
		break;
	default:
		break;
	}
}

void Archer::print()
{
	cout << "---ARCHER---\n";
	cout << "HP-" << this->getHp()<<endl;

}


