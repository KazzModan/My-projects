#pragma once
#include <iostream>
#include "Product.h"
#include <vector>
using std::cout;
using std::vector;
class Shop
{
	vector<Product*> products;
public:
	void addProd(Product* product);
	void deleteProd(size_t index);
	vector<Product*>& getProd() { return this->products; }
	Shop();
};

