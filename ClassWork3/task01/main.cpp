#include <iostream>
#include "Humans.h"
#include "float.h"
#include"Houses.h"
using namespace std;
void CreateHouse(House& hous);
House* AddHouse(House* houses, size_t& size, House& house);

int main()
{
	Float flat;
	House* houses=nullptr;
	int choose;
	House hous;
	Humans human;
	size_t size = 0;
	
		CreateHouse(hous);
		houses=AddHouse(houses, size, hous);
		
		flat.CreateNewPerson(human);
		flat.AddNewHuman( human);
		houses->Createflat(flat);
		houses->addNewFloat(houses, flat);

		houses->print();
	
	return 0;
}
void CreateHouse(House& hous)
{
	string street;
	cout << "Enter name of street";
	cin >> street;
	hous.setStreet(street);
}
House* AddHouse(House* houses, size_t& size, House& house)
{
	if (size == 0)
	{
		House* nHouse = new House[1];
		nHouse[0] = house;
		size++;
		return nHouse;
	}
}