#pragma once

#include <iostream>
#include <vector>
#include "Tree.h"
using namespace std;
class CarData
{
public:
	CarData();
	~CarData();
	void SetNumber(string number)
	{
		size_t counter=0;
		for (size_t i = 0; i < number.size(); i++)
		{
			if (!(number[i] >= '0' && number[i] <= '9'))
				counter++;
		}
		if (counter == 0)
			this->numberCar = number;
	}
	void setPen(string pen)
	{
		size_t counter = 0;

		for (size_t i = 0; i < pen.size(); i++)
		{
			if (!(pen[i] >= 'a' && pen[i] <= 'z'|| pen[i] >= 'A' && pen[i] <= 'Z'))
				counter++;
		}
		if (counter == 0)
			this->penaltys.push_back(pen);
	}
	bool operator <(CarData car) const
	{
		return this->numberCar < car.numberCar ? true : false;
	}
	bool operator >(CarData car) const
	{
		return this->numberCar > car.numberCar ? true : false;
	}
	bool operator >=(CarData car) const
	{
		return this->numberCar >= car.numberCar ? true : false;
	}
	bool operator <=(CarData car) const
	{
		return this->numberCar <= car.numberCar ? true : false;
	}
	bool operator ==(CarData car) const
	{
		return this->numberCar != car.numberCar ? true : false;
	}
	
private:
	string numberCar;
	vector<string> penaltys;
};


class Penalty
{
public:
	void addNewCar()
	{
		string number;
		CarData car;
		string pen;
		cout << "Enter number of car: ";
		cin >> number;
		car.SetNumber(number);
		if (this->tree.find(car) == nullptr)
		{
			cout << "Enter penalty: ";
			car.setPen(pen);
			this->tree.push(car);
			
		}
		else
		{
			CarData* data = this->tree.find(car);
			data->setPen(pen);
		}
	}
private:
	TemplateTree<CarData> tree;
};

