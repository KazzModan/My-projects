#include "Car.h"

Car::Car()
{
	weight = 0;
	brand = "";
	model = "";
	year = 0;
	volume = 0;
}

Car::Car(size_t weight, string brand, string model, size_t year, size_t volume)
{
	setBrand(brand);
	setWeight(weight);
	setModel(model);
	setYear(year);
	setVolume(volume);
}

void Car::setBrand(string brand) {
	if (!brand.empty())
	{
		this->brand = brand;
	}
}

void Car::setModel(string model) {
	if (!model.empty())
	{
		this->brand = model;
	}
}

void Car::setYear(size_t year)
{
	if (year > MIN_YEAR && year <= MAX_YEAR)
		this->year = year;
}
void Car::setVolume(size_t volume)
{
	if (year >= MIN_VALUE && year <= MAX_VOLUME)
		this->year = year;
}
void Car::setWeight(size_t weight)
{
	if ( weight<= MAX_WEIGHT && weight > MIN_VALUE)
	{
		this->weight = weight;
	}
}

string Car::getBrand() const {
	return this->brand;
}

string Car::getModel() const {
	return this->model;
}

size_t Car::getWeight() const {
	return this->weight;
}

size_t Car::getYear() const {
	return this->year;
}
size_t  Car::getVolume() const
{
	return this->volume;
}
