#pragma once
#include <iostream>
#include "BuildMats.h"
using namespace std;
class House
{
public:
	void onWork(BuildMats& mats)
	{
		mats.work();
		if (progress < 100)
			progress += mats.getProgress();
		else
			cout << "bulding is complete\n";
	}
	static void ShowMenu()
	{
		cout << "(1) Add brick.\n";
		cout << "(2) Add roof.\n";
		cout << "(3) Add cement.\n";
		cout << "(4) Add rabar.\n";
		cout << "(5) Add window.\n";
		cout << "(6) Exit.\n";
	}
	static void Menu()
	{
		bool isWork = true;

		char choose;
		Window window;
		Brick brick;
		Rebar reb;
		Cements cement;
		Roof roof;
		House house;
		do
		{
			ShowMenu();
			cout << "Enter: ";
			cin >> choose;
			switch (choose)
			{
			case '1':
				house.onWork(brick);
			case '2':
				house.onWork(roof);
			case '3':
				house.onWork(cement);
			case '4':
				house.onWork(reb);
			case '5':
				house.onWork(window);
			case '6':
				isWork = false;
			}
			}while (isWork);
		}

private:
	int progress;
};

