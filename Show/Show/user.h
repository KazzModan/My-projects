#pragma once
#include <iostream>
#include "checks.h"
using namespace std;
using namespace ch;
class user
{
public:
	bool setTitle(string title);
	string getTitle() const;
private:
	string name;
};

