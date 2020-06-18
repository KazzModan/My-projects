#include "Database.h"

Database::Database()
{
	// empty
}

Database::~Database()
{
	// empty
}

void Database::enter()
{
	bool exit = false;
	int choice;

	User temp;

	do
	{
		cout << "----LOGIN----\n\n";
		cout << "1. Login\n";
		cout << "2. Register\n";
		cout << "0. Exit\n";
		cout << "Enter: ";
		cin >> choice;

		system("cls");
		switch (choice)
		{
		case 1:
			login();
			break;

		case 2:
			temp.reg();
			users.push_back(temp);
			break;

		case 0:
			exit = true;
		}
	} while (!exit);
}

void Database::login()
{
	char cName[256];
	char cPassword[256];
	string sName;
	string sPassword;

	cout << "Enter name: ";
	cin >> cName;

	system("cls");

	cin.get();
	cout << "Enter password: ";
	cin >> cPassword;

	system("cls");

	sName = cName;
	sPassword = cPassword;

	if (checkAdmin(sName, sPassword))
	{
		adminPanel();
	}

	for (User item : users)
	{
		if (item.login(sName, sPassword))
		{
			item.menu(products);
		}
	}

}

void Database::adminPanel()
{
	bool exit = false;
	int choice;
	char cTemp;

	bool deleted = false;

	do
	{
		system("cls");

		cout << "----ADMIN_PANEL----\n\n";
		cout << "1. Edit products\n";
		cout << "2. Add product\n";
		cout << "3. Del product\n";
		cout << "4. Show all\n";
		cout << "0. Exit\n";
		cout << "Enter: ";
		cin >> choice;

		system("cls");
		switch (choice)
		{
		case 0:
			exit = true;
			return;

		case 1:
			for (Product item : products)
			{
				cout << "NAME: " << item.getName() << endl;
				cout << "Edit this product? [Y/N]: ";
				cin >> cTemp;
				switch (cTemp)
				{
				case'Y':
				case 'y':
					item.menu();
				}
			}
			break;

		case 2:
			addProduct();
			break;

		case 3:
			deleted = false;
			for (Product item : products)
			{
				cout << "NAME: " << item.getName() << endl;
				cout << "Delete this product? [Y/N]: ";
				cin >> cTemp;
				switch (cTemp)
				{
				case'Y':
				case 'y':
					delProduct(item);
					system("cls");
					deleted = true;
				}
				if (deleted)
					break;
			}
			break;

		case 4:
			for (Product item : products)
			{
				item.print();
			}
			system("pause");
			break;
		}
	} while (!exit);
}

bool Database::checkAdmin(string name, string password)
{
	fstream fin("config.txt");

	string temp;

	fin >> temp;

	if (temp != name)
		return false;

	fin >> temp;

	if (temp != password)
		return false;

	fin.close();
	return true;
}

void Database::addProduct()
{
	Product temp;

	char cTemp[256];
	float price;
	size_t count;
	string str;

	system("cls");

	cin.get();
	cout << "Enter name: ";
	cin.getline(cTemp, 256);
	str = cTemp;
	temp.setName(str);

	system("cls");

	cout << "Enter info: ";
	cin.getline(cTemp, 256);
	str = cTemp;
	temp.setInfo(str);

	system("cls");

	cout << "Enter price: ";
	cin >> price;
	temp.setPrice(price);

	system("cls");

	cout << "Enter count: ";
	cin >> count;
	temp.setCount(count);

	products.push_back(temp);
}

void Database::delProduct(const Product& product)
{
	products.remove(product);
}
