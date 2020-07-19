#include "Houses.h"
#include "float.h"
#include <iostream>

using namespace std;
void House::Createflat(Float& flat)
{
	int square;
	bool tarakani;
	cout << "Enter square of ploat: ";
	cin >> square;
	flat.setSquare(square);
	cout << "is tarakani here? 0-no, another number yes\n";
	cin >> square;
	if (square == 0)
		tarakani = false;
	else
		tarakani = true;
	flat.setTarakani(tarakani);
	cout << "Enter number of float\n";
	cin >> square;
	flat.setNumbersFloat(square);
}

void House::addNewFloat(House* house, Float& flat)
{
	if (house->floats == nullptr)
	{
		house->floats = new Float[1];
		house->floats[0] = flat;
		this->quantutyOfFloats++;
	}
	Float* flats = new Float[this->quantutyOfFloats];
	for (size_t i = 0; i < this->quantutyOfFloats; i++)
		flats[i] = house->floats[i];
	house->floats = new Float[this->quantutyOfFloats + 1];
	for (size_t i = 0; i < this->quantutyOfFloats; i++)
		house->floats[i] = flats[i];
	house->floats[this->quantutyOfFloats] = flat;
	this->quantutyOfFloats++;
}

void House::setStreet(string street)
{
	this->nameOfStreet = street;
}

void House::print() 
{
	for (size_t i = 0; i < this->quantutyOfFloats; i++)
	{
		cout << i << " flat:\n";
			this->floats[i].print();
	}
}
