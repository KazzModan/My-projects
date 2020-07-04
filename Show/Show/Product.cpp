#include "Product.h"

bool Product::setTitle(string title)
{
	return CheckTitle(this->title, title);
}

bool Product::setInfo(string info)
{
	return CheckTitle(this->info,info);
}

bool Product::setPrice(size_t price)
{
	if (price > MIN_PRICE && price < MAX_PRICE)
	{
		this->price = price;
		return true;
	}
	return false;
}

string Product::getTitle() const
{
	return this->title;
}

string Product::getInfo() const
{
	return this->info;
}

size_t Product::getPrice() const
{
	return this->price;
}
