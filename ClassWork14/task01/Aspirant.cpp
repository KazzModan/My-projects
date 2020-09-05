#include "Aspirant.h"

Aspirant::Aspirant(string name, size_t age, size_t marks, string profession, string nameOfWork) : Student(FIO, avgMark, age)
{
	setFio(name);
	setMark(marks);
	setAge(age);
	setProffesion(profession);
	setNameOfWork(nameOfWork);
}

void Aspirant::setProffesion(string prof)
{
	if (!prof.empty())
	this->profession = prof;

}

void Aspirant::setNameOfWork(string name)
{
	if (!name.empty())
		nameOfWork = name;
}

void Aspirant::print()
{
	Student::print();
	cout << "Name of his work: " << nameOfWork<<endl;
	cout << "His proffesion: " << profession << endl;
}
