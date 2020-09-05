#include "Car.h"

Car::Car(string name, size_t year, size_t volume, size_t price)
{
	this->setName(name);
	this->setPrice(price);
	this->setVoume(volume);
	this->setYear(year);
}

bool Car::setName(string name)
{
	if (CheckTitle(this->name, name))
		return true;
	return false;

}

bool Car::setYear(size_t year)
{
	if (year >= MIN_YEAR && year <= MAX_YEAR)
	{
		this->yearOfConstruction = year;
		return true;
	}
	return false;
}

bool Car::setVoume(size_t volume)
{
	if (volume >= MIN_VOlUME && volume <= MAX_VOLUME)
	{
		this->volumeOfMotor = volume;
		return true;
	}
	return false;
}

bool Car::setPrice(size_t price)
{
	if (price >= MIN_VOlUME && price <= MAX_VOLUME)
	{
		this->price = price;
		return true;
	}
	return false;
}

void Car::print()
{
	cout << "Name of car: " << this->name << endl;
	cout << "Year of construction: " << this->yearOfConstruction << endl;
	cout << "Engine volum: " << this->volumeOfMotor << endl;
	cout << "Price: " << this->price;
}
string Car::getTitle() const
{
	return this->name;
}

size_t Car::getYearOfConstruction() const
{
	return this->yearOfConstruction;
}

size_t Car::getEngineVolume() const
{
	return this->volumeOfMotor;
}

size_t Car::getPrice() const
{
	return this->price;
}