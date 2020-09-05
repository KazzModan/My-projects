#pragma once
#include <iostream>
#include <map>

using std::string;
using std::cout;
using std::endl;
#define SIZE 3
class Doc
{
public:
	Doc();
	string parts[SIZE];
	void setPart(size_t index, string value);
	string getPart(size_t index);
	void Show();
};
