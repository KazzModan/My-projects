#pragma once
#include <iostream>
#include "Car.h"
#include "checks.h"
using namespace ch;
using namespace std;
enum LIMITS
{
	MIN_YEAR = 1999,MAX_YEAR=2020,MIN_VOlUME=0,MAX_VOLUME=100,MIN_PRICE=0,MAX_PRICE=1000000
};
class Car
{
public:
	Car(string name = "", size_t year = 0, size_t volume = 0, size_t price = 0);
	bool setName(string name);
	bool setYear(size_t year);
	bool setVoume(size_t volume);
	bool setPrice(size_t price);
	void print();
	string getTitle() const;
	size_t getYearOfConstruction() const;
	size_t getEngineVolume() const;
	size_t getPrice() const;
private:
	string name;
	size_t yearOfConstruction;
	size_t volumeOfMotor;
	size_t price;
};