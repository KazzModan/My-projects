#pragma once
#include "Shop.h"
#include "Product.h"
class Proxy
{
	Shop shop;
public:
	Proxy(Shop shop);

	void buy(size_t index, size_t quantity);
};

