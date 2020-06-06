#include <iostream>
#include"Str.H"

Str::Str()
{
	_size = 1;
	_str = new char[1];
	_str[0] ='\0';
}
Str::Str(char* str,size_t size)
{
	_size = size;
	_str = new char[size];
	strcpy_s(_str, size, str);
}

Str::~Str()
{
	_str = nullptr;
	_size = 0;
}

void Str::setStr(char* str,size_t size)
{
	if (str != nullptr)
		_str = new char[size];
		strcpy_s(_str, size, str);
}

char* Str::getStr() const
{
	return _str;
}
void Str::print()
{
	cout << _str;
}
void Str::operator=(Str str)
{
	setStr(str._str, str._size);
}
void Str::operator+=(Str str)
{
	int newSize = str._size + _size +1;
	strcat_s(_str, newSize, str._str);
}
char* Str::operator+(Str str)
{
	int newSize = str._size + _size + 1;
	char* line= new char [newSize];
	strcat_s(_str, newSize, str._str);
	 strcat_s(line, newSize, str._str);
	 return line;
}
bool Str::operator>(char* line)
{
	if (strcmp(this->_str, line) == 1)
		return true;
	return false;
}
bool Str::operator<(char* line)
{
	if (strcmp(this->_str, line) == -1)
		return true;
	return false;
}
bool Str::operator==(char* line)
{
	if (strcmp(this->_str, line) == 0)
		return true;
	return false;
}
bool Str::operator>=(char* line)
{
	if (strcmp(this->_str, line) == 1|| strcmp(this->_str, line) == 0)
		return true;
	return false;
}
bool Str::operator<=(char* line)
{
	if (strcmp(this->_str, line) == -1 || strcmp(this->_str, line) == 0)
		return true;
	return false;
}
bool Str::operator!=(char* line)
{
	if (strcmp(this->_str, line) != 0)
		return true;
	return false;
}
void Str::operator!()
{
	int count = 0;
	char* temp = new char[_size];
	for (size_t i = 0; i < _size; i++)
	{
		temp[i] = _str[i];
	}
	for (size_t i = _size-1; i >0; i++)
	{
		_str[count++] = temp[i];
	}
}
char Str::operator[](int index)
{
	return index > 0 && index < _size?_str[index]:'0';
}
void Str::operator=(string text)
{
	delete[] _str;
	_size = text.length() + 1;
	_str = new char[_size];

	for (size_t i = 0; i < _size; i++)
		_str[i] = text[i];
}


ostream& operator<<(ostream& output, const Str& Str)
{
	output << "Str:" << Str._str << endl;
	return output;
}
