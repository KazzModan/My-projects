#include "Admin.h"

Admin::Admin()
{
	//clear
}

void Admin::addToDo(string toDo)
{
	if (!toDo.empty())
		this->listToDo.push_back(toDo);
}

string Admin::operator[](size_t index)
{
	if (index > this->listToDo.size() - 1)
		throw "eror: wrong index!";
	
	return this->listToDo[index];
}