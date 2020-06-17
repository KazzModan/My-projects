#include "lCar.h"

void lCar::setCount(size_t count)
{
	if (count > MIN && count < MAX_COUNT)
		this->countOfPersons = count;
}

void lCar::setfunc(string func)
{
	if (!func.empty())
		this->additonalFunctional.push_back(func);
}

lCar::lCar(size_t count, string func, size_t weight, string brand, string model, size_t year, size_t volume) : Car(weight, brand, model, year, volume)
{
	setCount(count);
	setfunc(func);
	setWeight(weight);
	setBrand(brand);
	setModel(model);
	setYear(year);
	setVolume(volume);
}

void lCar::print()
{
	cout << "Weight: " << getWeight()<<endl;
	cout << "Brand: " << getBrand() << endl;
	cout << "Model: " << getModel() << endl;
	cout << "year of selling: " << getYear() << endl;
	cout << "volume of engine: " << getVolume() << endl;
}

lCar::~lCar()
{
	this->volume = 0;
	this->brand = "";
	this->model = "";
	this->weight = 0;
	this->year = 0;
	this->additonalFunctional.clear();
}
