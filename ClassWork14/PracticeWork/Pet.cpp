#include "Pet.h"

#define CHECK(var) ((var[i] >='0' && var[i] <= '9') || (var[i] >= '' && var[i] <= '') || var[i] >= ' ')

Pet::Pet()
{
	this->name = "";
	this->age = 0;
}

Pet::Pet(string name, size_t age)
{
	if (setName(name))
		if (!setAge(age))
			return;
	else
		return;
}

Pet::Pet(string name, string sound, size_t age)
{
	if (setName(name))
		if (setAge(age))
			if (!setSound(sound))
				return;
		else
			return;
	else
		return;
}

bool Pet::setName(string name)
{
	size_t tempLenght = 0;
	size_t nameLenght = name.length();
	if (!(nameLenght >= MIN_LENGHT && nameLenght <= MAX_LENGHT))
		return false;
	for (size_t i = 0; i < nameLenght; i++)
		if ((name[i] >= '0' && name[i] <= '9') || 
			(name[i] >= 'a' && name[i] <= 'z') || 
			(name[i] >= 'A' && name[i] <= 'Z') || name[i] >= ' ')
			tempLenght++;

	if (nameLenght == tempLenght)
	{
		this->name = name;
		return true;
	}
	return false;
}

bool Pet::setAge(size_t age)
{
	if (age >= MIN_AGE && age <= MAX_AGE)
	{
		this->age = age;
		return true;
	}
	return false;
}

bool Pet::setSound(string sound)
{
	size_t tempLenght = 0;
	size_t soundLenght = name.length();
	if (!(soundLenght >= MIN_LENGHT && soundLenght <= MAX_LENGHT))
		return false;
	for (size_t i = 0; i < soundLenght; i++)
		if ((name[i] >= 'a' && name[i] <= 'z') ||
			(name[i] >= 'A' && name[i] <= 'Z') || name[i] >= ' ')
			tempLenght++;

	if (soundLenght == tempLenght)
	{
		this->sound = sound;
		return true;
	}
	return false;
}

string Pet::getName() const
{
	return this->name;
}

size_t Pet::getAge() const
{
	return this->age;
}

string Pet::getSound() const
{
	return this->sound;
}

void Pet::showAll()
{
	cout << "Pet name: " << this->name << endl;
	cout << "Pet age: " << this->name << endl;
	cout << "Sound: " << this->name << endl;
}

void Pet::show()
{
	cout << "Pet name: " << this->name << endl;
}

Pet::~Pet()
{
}
