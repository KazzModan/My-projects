#pragma once
#include <iostream>
#include "Checks.h"
using std::string;
using std::cout;
using std::endl;

class Offense
{
public:
	Offense();

	/*setters*/

	bool setTitle(string title);
	bool setInfo(string info);
	bool setFine(size_t fine);

	/*getters*/

	string getTitle() const;
	string getInfo() const;
	size_t getFine() const;

	void print() const;

private:
	string title;
	string info;
	size_t fine;

};

