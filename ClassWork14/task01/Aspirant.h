#pragma once
#include <iostream>
#include "Student.h"
using namespace std;
class Aspirant : protected Student
{
public:
	Aspirant(string name, size_t age, size_t marks, string profession, string nameOfWork);
	void setProffesion(string prof);
	void setNameOfWork(string name);
	void print();
private:
	string profession;
	string nameOfWork;
};

