#pragma once
#include <iostream>
#include "Worker.h"
using namespace std;
using namespace ch;
class Designer :protected Worker
{
public:
	Designer(size_t counter = 0, string portfolio = "", string name = "", size_t age = 0,
	size_t expirience = 0, size_t rating = 0, size_t sallary = 0, Status status = Status::NONE);
	bool setPortfolio(string mail);
	bool setWork(size_t counter);
	void print();
protected:
	string portfolio;
	size_t counterOfWorks;
};
