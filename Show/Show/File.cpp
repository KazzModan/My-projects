#include "File.h"

File::File()
{
}

void File::toFile(Database base)
{
	this->file.open("Product.txt");
	for (size_t i = 0; i < 5; i++)
	{
		this->file << "Name: " << base.arr[i].getTitle() << endl;
		this->file << "Info: " << base.arr[i].getInfo() << endl;
		this->file << "Info: " << base.arr[i].getPrice() << endl;
	}
	this->file.close();
	this->file.open("User.txt");
	for (size_t i = 0; i < 2; i++)
	{
		this->file << "Name: " << base.uArr[i].getTitle() << endl;
	}
	this->file.close();
}
