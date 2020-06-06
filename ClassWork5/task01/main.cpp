#include <iostream>
#include "Str.h"
using namespace std;

int main()
{
	char* word1 = new char[100];
	cin >> word1;
	Str line;
	Str line1(word1, 100);
	string string = "hola";
	line = line1;
	cout << line;
	line = string;
	cout << line;
	line += line1;
	cout << line;

	return 0;
}