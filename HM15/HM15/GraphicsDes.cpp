#include "GraphicsDes.h"

bool GraphicsDes::setLogos(string logos)
{
	if (CheckLettersAndNumbers(logos))
	{
		this->logos.push_back(logos);
		return true;
	}
	return false;
}
bool GraphicsDes::setLoayots(string layots)
{
	if (CheckLettersAndNumbers(layots))
	{
		this->layouts.push_back(layots);
		return true;
	}
	return false;
}

GraphicsDes::GraphicsDes(size_t counter, string portfolio, string name, size_t age, size_t expirience, size_t rating, size_t sallary, Status status, string works, string templates, string layout, string banner, string logos) : Designer(counterOfWorks, portfolio, name, age, expirience, positionRatings, salary, status)
{
	setAge(age);
	setName(name);
	setExpirience(expirience);
	setPositionRatings(rating);
	setSalary(sallary);
	setStatus(status);
	setPortfolio(portfolio);
	setWork(counter);
	setbanners(banner);
	setLogos(logos);
	setLoayots(layout);
}

void GraphicsDes::print()
{
	Designer::print();
}

bool GraphicsDes::setbanners(string banner)
{
	if (CheckLettersAndNumbers(banner))
	{
		this->banners.push_back(banner);
		return true;
	}
	return false;
}