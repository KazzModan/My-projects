#include "Offense.h"

Offense::Offense()
{
	this->title = "none";
	this->info = "none";
	this->fine = 0;
}

bool Offense::setTitle(string title)
{
	if (!CheckTitle(title))
		return false;

	this->title = title;
	return true;
}

bool Offense::setInfo(string info)
{
	if (!CheckTitle(info))
		return false;

	this->info = info;
	return true;
}

bool Offense::setFine(size_t fine)
{
	if (fine >= 0 && fine <= 10000) 
	{
		this->fine = fine;
		return true;
	}
	return false;
}

string Offense::getTitle() const
{
	return this->title;
}

string Offense::getInfo() const
{
	return this->info;
}

size_t Offense::getFine() const
{
	return this->fine;
}

void Offense::print() const
{
	cout << "\ttitle: " << getTitle() << endl;
	cout << "\tinfo: " << getInfo() << endl;
	cout << "\tfine: " << getFine() << endl;
}
