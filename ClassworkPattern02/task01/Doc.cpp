#include "Doc.h"
#include <iostream>
#include <map>

using std::string;

Doc::Doc()
{
}

void Doc::setPart(size_t index, string value)
{
	if (index >= 0 && index < 3)
		parts[index] = value;
	else
		cout << "FUUUUUUUUUUU" << endl;
}

string Doc::getPart(size_t index)
{
	if (index >= 0 && index < 3)
		return parts[index];
	else
		cout << "FUUUUUUUUUUU" << endl;
}

void Doc::Show()
{
	cout << "Header: " <<  this->parts[0]<<endl;
	cout << "Content: " << this->parts[1] << endl;
	cout << "Etc: " << this->parts[2] << endl;

}
