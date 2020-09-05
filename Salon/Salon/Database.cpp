#include "Database.h"

void Database::addElement()
{
	Car car;
	string temp;
	size_t sTemp;
	do
	{
		cout << "Enter name of this car: ";
		cin >> temp;
	}
	while (!car.setName(temp));
	do
	{
		cout << "Enter year of construction of this car: ";
		cin >> sTemp;
	} while (!car.setYear(sTemp));
	do
	{
		cout << "Enter engines's volume of this car: ";
		cin >> sTemp;
	} while (!car.setVoume(sTemp));
	do
	{
		cout << "Enter price of this car: ";
		cin >> sTemp;
	} while (!car.setPrice(sTemp));
	this->listOfCars.push_back(car);
}

void Database::deleteElement()
{
	size_t index;

	do
	{
		cout << "Enter index: ";
		cin >> index;
	} while (index >= this->listOfCars.size());
	this->listOfCars.erase(listOfCars.begin() + index);
}

void Database::ShowAll()
{
	for (size_t i = 0; i < this->listOfCars.size(); i++)
	{
		listOfCars[i].print();
	}
}

void Database::SearchByName(string name)
{
	for (size_t i = 0; i < this->listOfCars.size(); i++)
	{
		if (listOfCars[i].getTitle() == name)
			listOfCars[i].print();
	}
}

void Database::SearchByYear(size_t year)
{
	for (size_t i = 0; i < this->listOfCars.size(); i++)
	{
		if (listOfCars[i].getYearOfConstruction() == year)
			listOfCars[i].print();
	}
}

void Database::SearchByVolume(size_t volume)
{
	for (size_t i = 0; i < this->listOfCars.size(); i++)
	{
		if (listOfCars[i].getEngineVolume == volume)
			listOfCars[i].print();
	}
}

void Database::SearchByPrice(size_t price)
{
	for (size_t i = 0; i < this->listOfCars.size(); i++)
	{
		if (listOfCars[i].getPrice() == price)
			listOfCars[i].print();
	}
}

Database::Database()
{

}
