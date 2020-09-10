#include "PrototypeFactory.h"
using std::cout;
using std::cin;
void ShowMenu()
{
	cout << "1 - Desert Eagle\n";
	cout << "2 - Makarov \n";
	cout << "3 - Mac10 \n";
	cout << "4 - Double Mac-10 \n";
	cout << "5 - GrenadeLauncher \n";
	cout << "6 - TommyGun \n";
	cout << "0 - Exit(Play)\n\n";
}

int main()
{
	PrototypeFactory prototype;
	Weapon* tempWeapon;
	vector <Weapon*> weapons;
	bool exit = false;
	char choice;
	const size_t ansiNumber = 48;
	do
	{
		ShowMenu();

		cout << "Enter your choice:\n";
		cin >> choice;
		if (choice == '0')
		{
			exit = true;
			break;
		}

		tempWeapon = prototype.createWeapon(Weapons(size_t(choice - ansiNumber)));
		weapons.push_back(tempWeapon);
	} while (!exit);

	for (auto weapon : weapons)
		weapon->play();

	for (auto weapon : weapons)
		delete weapon;

	return 0;
}