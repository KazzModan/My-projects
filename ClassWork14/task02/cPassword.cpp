#include "cPassword.h"
void cPassword::setFid()
{
	this->fId = rand() % 312321;
}

void cPassword::setVisas(string visa)
{
	if (!visa.empty())
		this->visas = visa;
}
cPassword::cPassword(string FIO, string country, string gender, size_t age, string visas) :Passsport (FIO,Country,gender,age)
{
	setId();
	setFid();
	setFIO(FIO);
	setCountry(country);
	setAge(age);
	setVisas(visas);
	setGender(gender);
}
