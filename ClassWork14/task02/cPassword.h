#pragma once
#include <iostream>
#include <ctime>
#include "Passsport.h"

using namespace std;
class cPassword : protected Passsport
{
private:
	size_t fId;
	string visas;
	cPassword(string FIO, string coutnry, string gender, size_t age, string visas);
public:
	void setFid();
	void setVisas(string visa);
};

