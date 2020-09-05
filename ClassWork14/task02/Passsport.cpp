#include "Passsport.h"
void Passsport::setId()
{
	srand(time(nullptr));
	this->id = rand() % 222888;
}

void Passsport::setFIO(string fio)
{
	if (!fio.empty())
	{
		this->FIO = fio;
	}
}

void Passsport::setCountry(string country)
{
	if (!country.empty())
	{
		this->Country = country;
	}
}
void Passsport::print()
{
	cout << "FullName: " << this->FIO << endl;
	cout << "Age: " << this->age << endl;
	cout << "Coutnry: " << this->Country << endl;
	cout << "Gender: " << this->gender << endl;
	cout << "id: " << this->id;
}
void Passsport::setGender(string gender)
{
	if (!gender.empty())
	{
		this->gender = gender;
	}
}
Passsport::Passsport(string FiO, string country, string gender, size_t age)
{
	setFIO(FIO);
	setCountry(country);
	setGender(gender);
	setAge(age);
	setId();
}
void Passsport::setAge(size_t age)
{
	if (age>13&&age<125)
	{
		this->age = age;
	}
}