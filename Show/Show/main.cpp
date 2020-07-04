#include <iostream>
#include "Product.h"
#include "Database.h"
#include "File.h"
using namespace std;


int main()
{
	Database base;
	base.FillProduct();
	File file;
	file.toFile(base);
	return 0;
}