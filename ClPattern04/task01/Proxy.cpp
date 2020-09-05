#include "Proxy.h"

Proxy::Proxy(Shop shop)
{
	this->shop = shop;
}

void Proxy::buy(size_t index, size_t quantity)
{
	if (index < shop.getProd().size() && index >= 0)
	{
			shop.getProd()[index]->buy(quantity);
			if (shop.getProd()[index]->getQuantity() == 0)
				shop.deleteProd(index);
	}
}
