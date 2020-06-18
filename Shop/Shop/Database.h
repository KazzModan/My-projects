#pragma once

#include "User.h"
#include "Product.h"

#include <list>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class Database
{
public:
	Database();
	~Database();

	void enter();
	void login();
	void adminPanel();

	bool checkAdmin(string name, string password);

	void addProduct();
	void delProduct(const Product& product);

private:
	list<User> users;
	list<Product> products;
};

