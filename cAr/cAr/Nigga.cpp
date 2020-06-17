#include "Nigga.h"

Nigga::Nigga(string name, size_t count)
{
	this->countOfStollenCars = count;
	this->name = name;
}
void Nigga::stillCar(lCar& car)
{
	this->countOfStollenCars++;
	cout << this->name << "Stollen ur car,fcking rasist. BLM\n";
	car.~lCar();
}

void Nigga::stillCar(Truck& car)
{
	this->countOfStollenCars++;
	cout << this->name << "Stollen ur car,fcking rasist. BLM\n";
	car.~Truck();
}

void Nigga::print()
{
	cout << this->name << " he's, our brooo\n";
	cout << "he stollen " << this->countOfStollenCars << " cars\n";
}
