#pragma once
#include <iostream>

using namespace std;

class Water
{
public:
	Water();
	~Water();
	enum Type
	{
		OCEAN,SEA,LAKE,RIVER,SWAMP,NONE
	};
	Water(int depth, int weight, int lenght, Type type, string name);
	void setName(string name);
	void setLenght(int lenght);
	void setWeight(int weight);
	void setDepth(int depth);
	Type setType(Type type);
	int getLenght() const;
	int getDepth() const;
	int getWeight() const;
	string getType()const;
	void print();
	string getName() const;
	void square();
	void volume();
private:
	int lenght;
	int weight;
	int depth;
	Type type;
	string name;

};

