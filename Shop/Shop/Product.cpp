#include "Product.h"
#include <iostream>

Product::Product()
{
	name = "";
	info = "";
	price = 0;
	count = 0;
}

Product::~Product()
{
	// empty
}

string Product::getName() const
{
	return this->name;
}

string Product::getInfo() const
{
	return this->info;
}

float Product::getPrice() const
{
	return this->price;
}

size_t Product::getCount() const
{
	return this->count;
}

void Product::setName(string name)
{
	if (!name.empty())
		this->name = name;
}

void Product::setInfo(string info)
{
	if (!info.empty())
		this->info = info;
}

void Product::setPrice(float price)
{
	if (price > 0)
		this->price = price;
}

void Product::setCount(size_t count)
{
	if (count >= 0)
		this->count = count;
}

void Product::print() const
{
	cout << "-----\n";
	cout << "Product: " << this->name  << endl;
	cout << "Info:    " << this->info  << endl;
	cout << "Price:   " << this->price << endl;
	cout << "-----\n";
}

void Product::menu()
{
	bool exit = false;
	int choice;

	char cTemp[256];
	string sTemp;
	float price;
	int count;

	do
	{
		system("cls");

		cout << "----Edit menu----\n\n";
		cout << "1. Show info\n";
		cout << "2. Change name\n";
		cout << "3. Change info\n";
		cout << "4. Change price\n";
		cout << "5. Change count\n";
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
			print();
			system("pause");
			break;

		case 2:
			cin.get();
			cout << "Enter new name: ";
			cin.getline(cTemp, 256);
			sTemp = cTemp;
			setName(sTemp);
			break;

		case 3:
			cin.get();
			cout << "Enter new info: ";
			cin.getline(cTemp, 256);
			sTemp = cTemp;
			setInfo(sTemp);
			break;

		case 4:
			cout << "Enter new price: ";
			cin >> price;
			setPrice(price);
			break;

		case 5:
			cout << "Enter new count: ";
			cin >> count;
			setCount(count);
			break;
		}

	} while (!exit);
}

void Product::operator++(int)
{
	this->count++;
}

void Product::operator--(int)
{
	this->count--;
}

void Product::operator++()
{
	this->count++;
}

void Product::operator--()
{
	this->count--;
}

bool Product::operator==(const Product& product) const
{
	if (this->name == product.getName() &&
		this->info == product.getInfo() &&
		this->price == product.getPrice() &&
		this->count == getCount())
	{
		return true;
	}
	return false;
}
