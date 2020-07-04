#pragma once
#include <iostream>
#include "checks.h"
using namespace std;
using namespace ch;
enum  LIMITS
{
	MIN_PRICE = 0, MAX_PRICE=1500
};
class Product
{
public:
	// Incapsulation //
	bool setTitle(string title);
	bool setInfo(string info);
	bool setPrice(size_t price);
	string getTitle()const;
	string getInfo()const;
	size_t getPrice()const;

private:
	string title;
	string info;
	size_t price;
};

