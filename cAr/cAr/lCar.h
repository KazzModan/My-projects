#pragma once
#include "Car.h"
#include <list>
#include <iostream>
using namespace std;
class lCar : protected Car
{
public:
	void setCount(size_t count);
	void setfunc(string func);
	lCar(size_t count, string func, size_t weight, string brand, string model, size_t year,size_t volume);
	void print();
	~lCar();
private:
	size_t countOfPersons;
	list<string> additonalFunctional;
	enum LIMITS
	{
		MAX_COUNT = 5, MIN = 0
	};
};

