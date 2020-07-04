#include "Database.h"

void Database::FillProduct()
{
	string tName;
	size_t tSize;
	Product temp;
	for (size_t i = 0; i < 5; i++)
	{
		do
		{
			cout << "Enter name of " << i << " product: ";
			cin >> tName;
		}while(!temp.setTitle(tName));
		do
		{
			cout << "Enter info about " << i << " product: ";
			cin >> tName;
		} while (!temp.setInfo(tName));
		do
		{
			cout << "Enter price of " << i << " product: ";
			cin >> tSize;
		} while (!temp.setPrice(tSize));
		this->arr[i] = temp;
	}
	
}

void Database::FillUsers()
{
	for (size_t i = 0; i < 2; i++)
	{
		user temp;
		string tName;
		do
		{
			cout << "Enter name of " << i << " user: ";
			cin >> tName;
		} while (!temp.setTitle(tName));
		this->uArr[i] = temp;
	}
}

Database::Database()
{
}
