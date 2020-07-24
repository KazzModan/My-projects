#include "UserInterface.h"

void UserInterface::Menu()
{
	TemplateTree<CarData> database;

	bool menuWork = true;
	do
	{
		size_t choose;
		
		ShowMenu();

		cout << "enter your choose: ";
		lcin >> choose;

		system("cls");

		switch (choose)
		{
		case 0: 
			menuWork = false;
			break;
		case 1:
			FindCar(database);
			break;
		case 2:
			AddOffense(database);
			break;
		case 3:
			MultipleFind(database);
			break;
		case 4:
			database.print();
			break;
		}
	} while (menuWork);
}

void UserInterface::ShowMenu()
{
	cout << "1. find car\n";
	cout << "2. add offense\n";
	cout << "3. show by region or show by region and serias\n";
	cout << "4. show all\n";
	cout << "0. exit\n";
}

void UserInterface::AddOffense(TemplateTree<CarData>& database)
{
	string temp;
	CarData car;

	do
	{
		cout << "enter car number: ";
		lcin >> temp;
	} while (!car.setCarNumber(temp));

	CarData* find = database.find(car);
	
	if (find != nullptr) 
		find->addOffense();
	else 
	{
		do
		{
			cout << "enter car owner name: ";
			lcin >> temp;
		} while (!car.setOwnerName(temp));

		database.push(car);
		find = database.find(car);
		find->addOffense();
	}
}

bool UserInterface::FindCar(TemplateTree<CarData>& database)
{
	string temp;
	CarData car;

	do
	{
		cout << "enter car number: ";
		lcin >> temp;
	} while (!car.setCarNumber(temp));

	CarData* find = database.find(car);
	
	if (find != nullptr) 
	{
		cout << *find << endl;
		return true;
	}

	cout << "not found\n";

	return false;
}

void UserInterface::MultipleFind(TemplateTree<CarData>& database)
{
	string key;

	cout << "enter region [AA] or region and serias [AABB]: ";
	lcin >> key;
	
	database.multipleFind(key);
}
