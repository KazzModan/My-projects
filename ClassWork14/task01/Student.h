#pragma once
#include <iostream>
using namespace std;
class Student
{
protected:
	string FIO;
	size_t age;
	size_t avgMark;
public:
	Student(string fio,size_t age,size_t marks);
	void setAge(size_t age);
	void setMark(size_t mark);
	void setFio(string fio);
	string getFio()const;
	size_t getAge()const;
	size_t getMarks() const;
	void print() const;
};

