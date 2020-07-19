#pragma once
#include <iostream>

using namespace std;

class Humans
{
private:
	string name;
	string surname;
	int age;
public:
	Humans(string name, string surname, int age);
	Humans();
	~Humans();
	void setName(string name);
	void setSurname(string surname);
	void setAge(int age);
	string getName() const;
	string getSurname() const;
	int getAge() const;
	void print()const;
};
