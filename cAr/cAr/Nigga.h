#pragma once
#include <iostream>
#include "lCar.h"
#include "Truck.h"
using namespace std;
class Nigga
{
private:
	string name;
	size_t countOfStollenCars;
public:
	Nigga(string name, size_t count);
	void stillCar(lCar& car);
	void stillCar(Truck& car);
	void print();
};

