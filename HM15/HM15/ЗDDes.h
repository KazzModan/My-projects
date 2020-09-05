#pragma once
#include <iostream>
#include <vector>
#include "Designer.h"
class ÇDDes :protected Designer
{
public:
	bool setOBj(string obj);
	ÇDDes(size_t counter = 0, string portfolio = "", string name = "", size_t age = 0, size_t expirience = 0,
		size_t rating = 0, size_t sallary = 0, Status status = Status::NONE, string works = "", string templates = "", string obj = "");
	void print();
protected:
	vector <string> obj;
};

