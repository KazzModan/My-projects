#pragma once
#include <iostream>
#include "Product.h"
#include "user.h"
using namespace std;
using namespace ch;
class Database
{
public:
	void FillProduct();
	void FillUsers();
	Product arr[5];
	user uArr[2];
	Database();
};

