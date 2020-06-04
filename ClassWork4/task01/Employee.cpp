#pragma once
#include "Employee.h"
#include <iostream>
static size_t counter = 0;
using namespace std;

Employee::Employee()
{
	age = 0;
	name = "Noname";
	salary = 0;
	Position::NONE;
	counter++;
}

Employee::~Employee()
{
}

Employee::Employee(string name, float salary, int age, Position pos)
{
	setName(name);
	setAge(age);
	setPos(pos);
	setSalary(salary);
	this->id =counter;
	counter++;

}

Employee::Employee(const Employee& employee)
{
}

void Employee::setName(string name)
{
	if (!name.empty())
	{
		this->name = name;
	}
}

void Employee::setAge(int age)
{
	if (age > 18 && age < 60)
		this->age = age;
}

void Employee::setSalary(float salary)
{
	if (salary > 1000)
		this->salary = salary;
}

void Employee::setPos(Position pos)
{
	if (pos >= Position::NONE || pos <= Position::TESTER)
		this->myPos = pos;
}

void Employee::print()
{
	cout << "Name: " << getName()<<endl;
	cout << "Age: " << getAge() << endl;
	cout << " id: " << getId() << endl;
	cout << "salary: " << getSalary() << "$\n";
	cout << "Position: " << getPosition() << endl;
}

int Employee::getCounter()
{
	return counter;
}

void Employee::cmp(const Employee& emp1, const Employee& emp2)
{
	if (emp1.getSalary() > emp2.getSalary())
		cout << "Salary of "<<emp1.getName()<< " bigger\n";
	if (emp1.getSalary() < emp2.getSalary())
		cout << "Salary of " << emp1.getName() << " smaller\n";
	else
		cout << "salaries are same\n";
}

int Employee::getAge() const
{
	return this->age;
}

float Employee::getSalary() const
{
	return this->salary;
}

string Employee::getName() const
{
	return this->name;
}

int Employee::getId() const
{
	return this->id;
}

string Employee::getPosition() const
{
	switch (this->myPos)
	{
	case NONE:
		return "None";
	case DEVELOPER:
		return "Developer";
	case DESIGNER:
		return "Designer";
	case MANAGER:
		return "Manager";
	case TESTER:
		return "Tester";
	default:
		break;
	}
}

