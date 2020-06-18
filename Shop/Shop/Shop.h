#pragma once
#include "Product.h"
#include "User.h"
#include <list>
using namespace std;

class Shop
{
private:
	list<User> users;
	list<Product> products;

	bool logined;

	string tempPassword;
	string tempLogin;

public:
	Shop();

	void login();
	void menu();
	void adminPanel();

	void addUser();

	void addProduct();
	void deleteProduct();

	void buyProducts();
};

