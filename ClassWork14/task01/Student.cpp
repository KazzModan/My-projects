#include "Student.h"

Student::Student(string fio, size_t age, size_t marks)
{
	setAge(age);
	setFio(fio);
	setMark(marks);
}

void Student::setAge(size_t age)
{
	if (age > 17 && age < 100)
		this->age = age;
}
void Student::setMark(size_t mark)
{
	if (mark > 1 && mark < 13)
		this->avgMark = mark;
}
void Student::setFio(string fio)
{
	if (!fio.empty())
		this->FIO = fio;
}

string Student::getFio() const
{
	return this->FIO;
}
size_t Student::getAge() const
{
	return this->age;
}
size_t Student::getMarks() const
{
	return this->avgMark;
}

void Student::print() const
{
	cout << "Full name of student: " << this->getFio();
	cout << "Age of this student: " << this->getAge();
	cout << "Avg mark of this student: " << this->getMarks();
}
