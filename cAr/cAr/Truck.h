#pragma once
#include<iostream>
#include "Car.h"
using namespace std;

class Truck : protected Car
{
public:
	void setWeightofLoad(size_t weight);
	Truck(size_t weightOfLoad, size_t weight, string brand, string model, size_t year, size_t volume);
	void print();
	size_t getWeightOfLoad();
	~Truck();
private:
	size_t weightOfLoad;
	enum Limits 
	{
		MIN = 0, MAX_WEIGHT = 10000
	};
};
void Truck::print()
{
	cout << "Weight: " << getWeight() << endl;
	cout << "Brand: " << getBrand() << endl;
	cout << "Model: " << getModel() << endl;
	cout << "year of selling: " << getYear() << endl;
	cout << "volume of engine: " << getVolume() << endl;
	cout << "Weight of load" << getWeightOfLoad() << endl;
	
}

inline size_t Truck::getWeightOfLoad()
{
	return this->weightOfLoad;
}

inline Truck::~Truck()
{
	this->volume = 0;
	this->brand = "";
	this->model = "";
	this->weight = 0;
	this->year = 0;
	this->weightOfLoad = 0;
}

