#include <iostream>
#pragma once

using namespace std;
class Document
{
public:

	enum LvlOfAcces
	{
		NONE, SUCKER, WORKER, BOOKER, BOSS
	};
	void print();
	bool setName(string name);
	bool setSize(size_t size);
	bool setType(size_t acc);
	int getLvlv() const;
	Document();
	Document(size_t size, string name, size_t acc);
	~Document();
	bool  operator > (const Document& doc) const;
	bool  operator < (const Document& doc) const;
	bool  operator >= (const Document& doc) const;
	bool  operator <= (const Document& doc) const;
	string getName() const;
	size_t getSize() const;
private:
	size_t _size;
	string _name;
	LvlOfAcces _acces;
};

