#pragma once
#include<iostream>
#include"Humans.h"
#include <vector>
using namespace std;

class Float
{
private:
	vector <Humans> persons;
	size_t quantuty;
	size_t numberOfFloat;
	size_t square;
	bool isTarakaniHere;
public:
	Float();
	~Float();
	void CreateNewPerson(Humans& human);
	void AddNewHuman(Humans& human);
		void setNumbersFloat(size_t number);
	void setSquare(size_t square);
	void setTarakani(bool square);
	void print() const;
	size_t getQuantity();
};

