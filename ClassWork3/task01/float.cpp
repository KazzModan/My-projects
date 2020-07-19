#include <iostream>
#include "float.h"
#include "Humans.h"
using namespace std;

Float::Float()
{
	quantuty = 0;
	numberOfFloat = 0;
	square = 0;
	isTarakaniHere = true;
}

Float::~Float()
{
	quantuty = 0;
	numberOfFloat = 0;
	isTarakaniHere = false;
}
void Float::CreateNewPerson(Humans& human)
{
	string name;
	string surname;
	int age;
	cout << "Enter name of person: ";
	cin >> name;
	human.setName(name);
	cout << "Enter surname of person: ";
	cin >> surname;
	human.setSurname(surname);
	cout << "Enter age of person: ";
	cin >> age;
	human.setAge(age);
}
void Float::AddNewHuman(Humans& human)
{
	this->persons.push_back(human);
	quantuty++;
}
void Float::setNumbersFloat(size_t number)
{
	if (!(number < 0 || number>36))
	{
		this->numberOfFloat = number;
	}
}

void Float::setSquare(size_t square)
{
	if (!(square < 0 || square>120))
	{
		this->square = square;
	}
}

void Float::setTarakani(bool square)
{
		this->square = square;
}

void Float::print() const
{
	
		cout << "Number of float: " << this->numberOfFloat<<endl;
		cout << "square:" << this->square << endl;
		cout << "is tarakani here: ";
		this->isTarakaniHere == true ? cout << "yes: \n" : cout << "no\n";
		for (size_t i = 0; i < this->quantuty; i++)
		{
			this->persons[i].print();
		}
}
size_t Float::getQuantity()
{
	return this->quantuty;
}
