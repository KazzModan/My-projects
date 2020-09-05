#include <iostream>
#include "Product.h"
#include "Shop.h"
#include "Proxy.h"
int main()
{
	Product prod("onion", 20);
	Shop shop;
	shop.addProd(&prod);
	Proxy proxy(shop);
	proxy.buy(0, 3);
	shop.getProd()[0]->show();
	return 0;
}