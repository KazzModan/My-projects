#include "Product.h"

Product::Product(string name, size_t quantity)
{
	setName(name);
	setQuantity(quantity);
}

void Product::setName(string name)
{
	this->name = name;
}

void Product::setQuantity(size_t quantity)
{
	if(quantity>0)
	this->quantity = quantity;
}

void Product::show()
{
	std::cout << "name: " << this->name << std::endl;
	std::cout << "quantity: " << this->quantity << std::endl;
}

void Product::buy(size_t quantity)
{
	this->quantity -= quantity;
}
