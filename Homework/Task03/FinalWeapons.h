#pragma once
#include "Weapon.h"

class DesertEagle : public Weapon
{
	DesertEagle* clone()
	{
		setMaxQuantityAmmo(7);
		setLoadedAmmo(7);
		setQuantityAmmo(56);
		return new DesertEagle(*this);
	}
	DesertEagle* clone(size_t maxQuantity, size_t loadedAmmo, size_t quantityAmmo)
	{
		setMaxQuantityAmmo(maxQuantity);
		setLoadedAmmo(loadedAmmo);
		setQuantityAmmo(quantityAmmo);
		return new DesertEagle(*this);
	}
	void play() override
	{
		std::cout << "Desert Eagle shoots\n";
		oldPlay();
	}
};

class Makarov : public Weapon
{
	Makarov* clone()
	{
		setMaxQuantityAmmo(9);
		setLoadedAmmo(9);
		setQuantityAmmo(54);
		return new Makarov(*this);
	}
	Makarov* clone(size_t maxQuantity, size_t loadedAmmo, size_t quantityAmmo)
	{
		setMaxQuantityAmmo(maxQuantity);
		setLoadedAmmo(loadedAmmo);
		setQuantityAmmo(quantityAmmo);
		return new Makarov(*this);
	}
	void play() override
	{
		std::cout << "Makarov shoots\n";
		oldPlay();
	}
};

class Mac10 : public Weapon
{
	Mac10* clone()
	{
		setMaxQuantityAmmo(15);
		setLoadedAmmo(15);
		setQuantityAmmo(90);
		return new Mac10(*this);
	}
	Mac10* clone(size_t maxQuantity, size_t loadedAmmo, size_t quantityAmmo)
	{
		setMaxQuantityAmmo(maxQuantity);
		setLoadedAmmo(loadedAmmo);
		setQuantityAmmo(quantityAmmo);
		return new Mac10(*this);
	}
	void play() override
	{
		std::cout << "Mac-10 shoots\n";
		oldPlay();
	}
};

class DoubleMac10 : public Weapon
{
	DoubleMac10* clone()
	{
		setMaxQuantityAmmo(30);
		setLoadedAmmo(30);
		setQuantityAmmo(180);
		return new DoubleMac10(*this);
	}
	DoubleMac10* clone(size_t maxQuantity, size_t loadedAmmo, size_t quantityAmmo)
	{
		setMaxQuantityAmmo(maxQuantity);
		setLoadedAmmo(loadedAmmo);
		setQuantityAmmo(quantityAmmo);
		return new DoubleMac10(*this);
	}
	void play() override
	{
		std::cout << "Double Mac-10 shoots\n";
		oldPlay();
	}
};

class GrenadeLauncher : public Weapon
{
	GrenadeLauncher* clone()
	{
		setMaxQuantityAmmo(3);
		setLoadedAmmo(3);
		setQuantityAmmo(6);
		return new GrenadeLauncher(*this);
	}

	GrenadeLauncher* clone(size_t maxQuantity, size_t loadedAmmo, size_t quantityAmmo)
	{
		setMaxQuantityAmmo(maxQuantity);
		setLoadedAmmo(loadedAmmo);
		setQuantityAmmo(quantityAmmo);
		return new GrenadeLauncher(*this);
	}
	void play() override
	{
		std::cout << "Grenade Launcher shoots\n";
		oldPlay();
	}
};

class TommyGun : public Weapon
{
	TommyGun* clone()
	{
		setMaxQuantityAmmo(14);
		setLoadedAmmo(14);
		setQuantityAmmo(70);
		return new TommyGun(*this);
	}
	TommyGun* clone(size_t maxQuantity, size_t loadedAmmo, size_t quantityAmmo)
	{
		setMaxQuantityAmmo(maxQuantity);
		setLoadedAmmo(loadedAmmo);
		setQuantityAmmo(quantityAmmo);
		return new TommyGun(*this);
	}
	void play() override
	{
		std::cout << "Tommy-gun shoots\n";
		oldPlay();
	}
};