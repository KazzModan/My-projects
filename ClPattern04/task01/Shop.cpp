#include "Shop.h"

void Shop::addProd(Product* product)
{
	products.push_back(product);
}

void Shop::deleteProd(size_t index)
{
	if (index >= 0 && index < products.size())
		products.erase(products.begin() + index);
	else
		cout << "U entered wrong index\n";
}

Shop::Shop()
{
}
