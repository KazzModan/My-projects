#pragma once
#include <iostream>
#include <vector>
#include "checks.h"
#include "Car.h"
using namespace std;
using namespace ch;
class Database
{
public:
	void addElement();
	void deleteElement();
	void ShowAll();
	void SearchByName(string name);
	void SearchByYear(size_t year);
	void SearchByVolume(size_t volume);
	void SearchByPrice(size_t price);
	Database();
private:
	vector <Car> listOfCars;
};

