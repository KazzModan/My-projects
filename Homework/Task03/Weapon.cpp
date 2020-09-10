#include "Weapon.h"

bool Weapon::setLoadedAmmo(size_t quantity)
{
	if (quantity >= 0 && quantity <= this->loadedAmmo)
	{
		this->loadedAmmo = quantity;
		return true;
	}
	return false;
}

bool Weapon::setQuantityAmmo(size_t quantity)
{
	if (quantity >= 0 && quantity <= 100)
	{
		this->quantityAmmo = quantity;
		return true;
	}
	return false;
}

bool Weapon::setMaxQuantityAmmo(size_t maxQuantity)
{
	if (maxQuantity > this->loadedAmmo)
	{
		this->maxQuantityAmmo = maxQuantity;
		return true;
	}

	if (maxQuantity >= 0 && maxQuantity <= this->loadedAmmo)
	{
		this->maxQuantityAmmo = maxQuantity;
		this->loadedAmmo = maxQuantity;
		return true;
	}
	return false;
}

void Weapon::oldPlay()
{
	if (!shot())
	{
		std::cout << "No cartridges, rechargeable!\n";
		if (reload())
			std::cout << "Recharged!\n";
		else
			std::cout << "No cartridges or already loaded!\n";
	}
	else
		std::cout << "Shot!\n";
}

bool Weapon::reload()
{
	if (this->loadedAmmo == this->maxQuantityAmmo)
		return false;

	if (this->maxQuantityAmmo > this->quantityAmmo)
	{
		if (this->quantityAmmo + this->loadedAmmo > this->maxQuantityAmmo)
		{
			this->loadedAmmo = this->maxQuantityAmmo;
			this->quantityAmmo -= this->maxQuantityAmmo;
			return true;
		}

		this->loadedAmmo = this->quantityAmmo;
		this->quantityAmmo = 0;
		return true;
	}

	if (this->loadedAmmo != 0)
	{
		this->quantityAmmo += this->loadedAmmo;
		this->loadedAmmo = this->maxQuantityAmmo;
		this->quantityAmmo -= this->maxQuantityAmmo;
		return true;
	}
	else
	{
		this->loadedAmmo = this->maxQuantityAmmo;
		this->quantityAmmo -= this->maxQuantityAmmo;
		return true;
	}
	return false;
}

bool Weapon::shot()
{
	if ((this->loadedAmmo == 0) && (this->quantityAmmo == 0))
		return false;

	if ((this->loadedAmmo == 0) && (this->quantityAmmo != 0))
		return false;

	if (this->loadedAmmo != 0)
	{
		this->loadedAmmo--;
		return true;
	}
	return false;
}
