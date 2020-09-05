#include <iostream>
#include "checks.h"
using namespace std;
using namespace ch;
int main()
{
	string check = "123456789@gmail.com";
	if (CheckMail(check))
		cout << "Hello";
}