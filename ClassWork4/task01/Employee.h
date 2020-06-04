#pragma once
#include <iostream>
using namespace std;

class Employee
{
public:
	enum Position
	{
		NONE, DEVELOPER, DESIGNER, MANAGER, TESTER
	};
	Employee();
	~Employee();
	Employee(string name, float salary, int age, Position pos);
	Employee(const Employee& employee);

	void setName(string name);
	void setAge(int age);
	void setSalary(float salary);
	void setPos(Position pos);
	void print();
	static int getCounter();
	static void cmp(const Employee& emp1, const Employee& emp2);
private:
	
	int getAge()const;
	float getSalary() const;
	string getName() const;
	int getId()const ;
	string getPosition()const;
private:
	int age;
	float salary;
	string name;
	int id;
	Position myPos;
};

