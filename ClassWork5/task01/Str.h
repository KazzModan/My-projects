#pragma once
#include <iostream>
#include <string>
using namespace std;

class Str
{
public:
	Str();
	Str(char* str,size_t size);
	~Str();
	void setStr(char* str, size_t size);
	char* getStr() const;
	void print();
	void operator=(string text);
	void operator=(Str str);
	void operator=(string text);

	void operator+=(Str str);
	char* operator+(Str str);
	bool operator> (char* line);
	bool operator<(char* line);
	bool operator==(char* line);
	bool operator>=(char* line);
	bool operator<=(char* line);
	bool operator !=(char* line);;
	friend ostream& operator<<(ostream& output, const Str& str);
	void operator !();
	char operator[] (int index);
private:
	char* _str=nullptr;
	size_t _size;
};