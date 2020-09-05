#include <iostream>
using namespace std;

double Input();

double Validation(double number);

int main()
{
	double number;
	cout << "Enter number\n";
	cin >> number;
	cout << Validation(number);
	return 0;
}

double Input()
{
	double amount;
	bool normal = false;
	cout << "Enter amount money: \n";
	cin >> amount;

	if (!cin)                                           // Check for extraneous characters
	{
		system("cls");
		cout << "!Error!\n";
		return 0;
	}
	do
	{
		if (normal)
		{
			cout << "Error! \nThe number is inadequate\n";
			cin >> amount;
			if (!cin)                                           // Check for extraneous characters
			{
				system("cls");
				cout << "!Error!\n";
				break;
			}
		}
		else
			normal = true;
	} while (amount < 0 || amount > 2000000);

	return amount - int(amount);
}

double Validation(double number)
{
	number = number + 1;
	return number;
}
