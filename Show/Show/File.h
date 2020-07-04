#pragma once
#include <iostream>
#include <fstream>
#include "Database.h"
using namespace std;
class File
{
private:
	
	ofstream file;
public:
	File();
	void toFile(Database base);
};

