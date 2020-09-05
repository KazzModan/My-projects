#include "Penalty.h"

void Penalty::addNewCar()
{
	string temp;
	int counter =-1;
	cout << "Enter number of car: ";
	cin >> temp;
	for (size_t i = 0; i < .size(); i++)
	{
		if(temp==l[i])
		{ 
			counter=i;
		}
	}
	Element el;
	
	if (counter == -1)
	{
		el.name = temp;
		this->tree.Insert(&el);
	}
	else
		l=

}
