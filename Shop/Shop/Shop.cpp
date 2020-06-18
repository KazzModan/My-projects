#include "Shop.h"
#include <stdio.h>
#include <stdlib.h>

Shop::Shop()
{
	logined = false;
	login();
}

void Shop::login()
{
	bool exit = false;
	do
	{
		int choice;
		system("cls");
		cout << "1. Login\n";
		cout << "2. Register\n";
		cin >> choice;

		system("cls");
		switch (choice)
		{
		case 1:
			exit = true;
			break;
		case 2:
			addUser();
			exit = true;
			break;
		}

		if (exit)
		{
			FILE* f = fopen("config.txt", "r");

			cout << "Enter login: ";
			cin >> tempLogin;
			cout << "Enter password: ";
			cin >> tempPassword;

			char temp[100];
			string tempStr;
			char charTemp;
			int indexTemp;
			for (int i = 0; (charTemp = fgetc(f)) != '\n'; i++)
			{
				temp[i] = charTemp;
				indexTemp = i;
			}
			temp[indexTemp + 1] = '\0';

			tempStr = temp;
			if (temp == tempLogin)
			{
				for (int i = 0; i < strlen(temp); i++)
				{
					temp[i] = '\0';
				}
				for (int i = 0; (charTemp = fgetc(f)) != '\n'; i++)
				{
					temp[i] = charTemp;
					indexTemp = i;
				}
				temp[indexTemp + 1] = '\0';

				tempStr = temp;
				if (temp == tempPassword)
				{
					adminPanel();
				}
			}

			fclose(f);

			for (User item : users)
			{
				if (item.enter(tempLogin, tempPassword))
				{
					logined = true;
					menu();
				}
			}
			exit = false;
		}

	} while (!exit);
}

void Shop::menu()
{
	system("cls");
	do
	{
		int choice;
		cout << "----MENU----\n\n";
		cout << "Balance: \n";
		for (User item : users)
		{
			if (item.enter(tempLogin, tempPassword))
			{
				cout << item.getCash() << "$\n";
			}
		}
		cout << "1. Settings\n";
		cout << "2. Show products\n";
		cout << "0. Exit\n";
		cout << "Enter:___\b\b\b";
		cin >> choice;

		switch (choice)
		{
		case 0:
			return;
		case 1:
			break;
		case 2:
			buyProducts();
			break;
		}

		system("cls");
	} while (true);

}

void Shop::adminPanel()
{
	system("cls");
	do
	{
		int choice;
		cout << "----AdminPanel----\n\n";
		cout << "1. Add product\n";
		cout << "2. Delete product\n";
		cout << "0. Exit\n";
		cout << "Enter:___\b\b\b";
		cin >> choice;

		switch (choice)
		{
		case 0:
			return;
		case 1:
			addProduct();
			break;
		}
	} while (true);
}

void Shop::addUser()
{
	User newUser;
	users.push_back(newUser);
}

void Shop::addProduct()
{
	Product temp;
	products.push_back(temp);
}

void Shop::buyProducts()
{
	for (Product item : products)
	{
		char temp;
		item.info();
		cout << "\nBuy this? [Y]es or [N]ou\n";
		cin >> temp;
		switch (temp)
		{
		case 'y':
			for (User itemUser : users)
			{
				if (itemUser.enter(tempLogin, tempPassword))
				{
					itemUser.buy(item);
				}
			}
		}
	}
}
