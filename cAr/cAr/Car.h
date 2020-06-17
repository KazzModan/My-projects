#pragma once
#include <iostream>
using namespace std;
class Car
{
public:
	Car();
	Car(size_t weight, string brand, string model, size_t year, size_t volume);
	void setWeight(size_t weight);
	void setBrand(string brand);
	void setModel(string model);
	void setYear(size_t year);
	string getBrand() const;
	string getModel() const;
	size_t getWeight() const;
	size_t getYear() const;
	void setVolume(size_t volume);
	size_t getVolume() const;

	enum LIMINTS
	{
		MAX_WEIGHT = 10000, MIN_VALUE = 0, MAX_YEAR = 2020, MAX_VOLUME = 10,MIN_YEAR=1893
	};
protected:
	size_t weight;
	string brand;
	string model;
	size_t year;
	size_t volume;
};

