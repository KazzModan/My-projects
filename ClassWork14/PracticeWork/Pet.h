#pragma once
#include <iostream>
using std::string;
using std::cout;
using std::cin;
using std::endl;

class Pet
{
public:
	Pet();
	Pet(string name, size_t age);
	Pet(string name, string sound, size_t age);

	bool setName(string name);
	bool setAge(size_t age);
	bool setSound(string sound);

	string getName() const;
	size_t getAge() const;
	string getSound() const;

	void showAll();
	void show();
	~Pet();

protected:
	enum Limits
	{
		MIN_AGE = 0,
		MAX_AGE = 100,

		MIN_LENGHT = 2,
		MAX_LENGHT = 30
	};
	string name;
	string sound;
	size_t age;
};
