#pragma once
#include <vector>
#include "Worker.h"
using std::vector;

class Admin : protected Worker
{
public:
	Admin();

	//add to do
	void addToDo(string toDo);

	//get to do
	string operator [] (size_t index);

private:
	vector<string> listToDo;
};