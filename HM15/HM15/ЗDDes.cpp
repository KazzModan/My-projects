#include "ÇDDes.h"

bool ÇDDes::setOBj(string obj)
{
	if (CheckLettersAndNumbers(obj))
	{
		this->obj.push_back(obj);
		return true;
	}
	return false;
}
ÇDDes::ÇDDes(size_t counter = 0, string portfolio = "", string name = "", size_t age = 0, size_t expirience = 0,
	size_t rating = 0, size_t sallary = 0, Status status = Status::NONE, string works = "", string templates = "", string obj = "") : Designer(counterOfWorks, portfolio, name, age, expirience, positionRatings, salary, status)
{
	setAge(age);
	setName(name);
	setExpirience(expirience);
	setPositionRatings(rating);
	setSalary(sallary);
	setStatus(status);
	setPortfolio(portfolio);
	setWork(counter);
	setOBj(obj);
}

void ÇDDes::print()
{
	Designer::print();
}
