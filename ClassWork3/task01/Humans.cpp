#include <iostream>
#include "Humans.h"
using namespace std;

Humans::Humans()
{
	name = "Noname";
	surname = "Nosurname";
	age = 0;
}
Humans::Humans(string name, string surname, int age)
{
	this->name = name;
	this->surname = surname;
	this->age = age;
}
Humans::~Humans()
{
	name = "";
	surname = "";
	age = 0;
}
void Humans::setName(string name)
{
	if (!name.empty())
		this->name = name;
}
void Humans::setSurname(string surname)
{
	if (!(surname.empty()) != 0)
		this->surname = surname;
}

void Humans::setAge(int age)
{
	if (!(age < 0 || age>125))
		this->age = age;
}
string Humans::getName() const
{
	return this->name;
}

string Humans::getSurname() const
{
	return this->surname;
}

int Humans::getAge() const
{
	return this->age;
}

void Humans::print()const
{
	cout << "Name of person: " << getName() << endl;
	cout << "Surname of person: " << getSurname() << endl;
	cout << "Age of person: " << getAge() << endl;
}
