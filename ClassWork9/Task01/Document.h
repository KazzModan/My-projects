#include <iostream>
#pragma once

using namespace std;
class Document
{
public:
	
	enum LvlOfAcces
	{
		SUCKER,WORKER,BOOKER,BOSS,NONE
	};
	void print();
	bool setName(string name);
	bool setSize(size_t size);
	bool setType(size_t acc);
	Document();
	Document(size_t size, string name, size_t acc);
	~Document();
private:
	size_t _size;
	string _name;
	LvlOfAcces _acces;

};

