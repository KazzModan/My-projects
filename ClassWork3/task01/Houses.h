#pragma once
#include<iostream>
#include"float.h"
class House
{
private:
	Float* floats;
	size_t quantutyOfFloats;
	string nameOfStreet;
public:
	House()
	{
		floats = nullptr;
		quantutyOfFloats = 0;
	}
	void Createflat(Float& flat);
	void addNewFloat(House* house, Float& flat);
	void setStreet(string street);
 void print() ;
};
