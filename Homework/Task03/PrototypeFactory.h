#pragma once
#include "FinalWeapons.h"
#include <vector>
using std::vector;

enum class Weapons
{
	DesertEagle,
	Makarov,
	Mac10,
	DoubleMac10,
	GrenadeLauncher,
	TommyGun,
};
class PrototypeFactory
{
	 vector<Weapon*> prototypes;

public:
	PrototypeFactory()
	{
		this->prototypes =
		{ new DesertEagle(),   new Makarov(),
		new Mac10(),   new DoubleMac10(),
		new GrenadeLauncher(),   new TommyGun(), };
	}
	Weapon* createWeapon(Weapons typePlayer)
	{
		return this->prototypes[static_cast<size_t>(typePlayer) - 1]->clone();
	}
	~PrototypeFactory()
	{
		this->prototypes.clear();
	}
};

