#pragma once

#include "Product.h"

#include <list>
#include <string>
using namespace std;

class User
{
public:
	User();
	~User();
	 
	string getName() const;
	string getEmail() const;
	string getNumber() const;
	string getPassword() const;
	float getCash() const;

	void setName(string name);
	void setEmail(string email);
	void setNumber(string number);
	void setPassword(string password);
	void setCash(float cash);

	void reg();
	bool login(string name, string password);
	void putCash();
	bool buy(Product& p);
	void print() const;
	void printInventory() const;
	void menu(list<Product>& products);

private:
	string name;
	string email;
	string number;
	string password;
	float cash;

	list<Product> inventory;
};

