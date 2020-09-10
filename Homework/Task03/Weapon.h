#pragma once
#include <iostream>

class Weapon abstract
{
public:
	virtual Weapon* clone() = 0;
	virtual void play() = 0;
	virtual ~Weapon() {}

	bool setLoadedAmmo(size_t quantity);
	bool setQuantityAmmo(size_t quantity);
	bool setMaxQuantityAmmo(size_t maxQuantity);

	void oldPlay();
	bool reload();
	bool shot();
protected:
	size_t quantityAmmo;
	size_t loadedAmmo = 0;
	size_t maxQuantityAmmo;
};

