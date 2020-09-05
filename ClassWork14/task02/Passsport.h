#pragma once
#include <iostream>
#include <ctime>
using namespace std;
class Passsport
{
public:
	void setId();
	void setFIO(string fio);
	void setCountry(string country);
	void print();
	void setAge(size_t age);
	void setGender(string gender);
	Passsport(string FiO, string country, string gender, size_t age);
protected:
	size_t id;
	string FIO;
	string Country;
	string gender;
	size_t age;
};

