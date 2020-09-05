#include "Developer.h"

Technologie::Technologie()
{
	this->title = "no title";
	this->description = "no description";
}

bool Technologie::setTitle(string title)
{
	return ch::CheckTitle(this->title, title);
}

bool Technologie::setDescription(string description)
{
	return ch::CheckTitle(this->description, description);
}

string Technologie::getTitle() const
{
	return this->title;
}

string Technologie::getDescription() const
{
	return this->description;
}

void Technologie::print() const
{
	cout << "title: " << getTitle() << endl;
	cout << "descripion: " << getDescription() << endl;
}

Developer::Developer() : Worker()
{
	//clear
}

Developer::Developer(const WorkerData& worker) : Worker(worker.name, worker.age, worker.expirience, worker.salary, worker.positionRatings, worker.status)
{
	//clear
}

void Developer::addTechnologie(Technologie tech)
{
	this->listWithTechologies.push_back(tech);
}

size_t Developer::getQuentityOfWorks() const
{
	return this->listWithTechologies.size();
}

void Developer::print() const
{
	Worker::print();

	for (size_t i = 0; i < getQuentityOfWorks(); i++)
		this->listWithTechologies[i].print();
}
