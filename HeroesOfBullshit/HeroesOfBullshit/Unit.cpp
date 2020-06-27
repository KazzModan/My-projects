#include "Unit.h"

void Unit::setHp(size_t hp)
{
	if (hp > MIN && hp <= MAX)
		this->hp = hp;
}
void Unit::setDmg(size_t dmg)
{
	if (dmg > MIN && dmg <= MAX)
		this->dmg = dmg;
}
void Unit::setDodge(size_t chanceToDodge)
{
	if (chanceToDodge > MIN && chanceToDodge <= MAX)
		this->chanceToDodge = chanceToDodge;
}

void Unit::setType(Type type)
{
	this->type = type;
}

Unit::Unit(size_t hp, size_t dmg, size_t dodge, Type type)
{
	setHp(hp);
	setDmg(dmg);
	setDodge(dodge);
	setType(type);
}

size_t Unit::getHp() const
{
	return this->hp;
}
