#pragma once
#include <iostream>
using std::string;
class Product
{
	string name;
	size_t quantity;
    public:
	Product(string name = "noname", size_t quantity = 0);
	void setName(string name);
	void setQuantity(size_t quantity);
	string getName() { return this->name; }
	size_t getQuantity() { return this->quantity; }
	void show();
	void buy(size_t quantity);
};

