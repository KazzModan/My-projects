#include "Designer.h"

Designer::Designer(size_t counter, string portfolio, string name, size_t age, size_t expirience, size_t rating, size_t sallary, Status status) : Worker(name,age,expirience,salary,positionRatings,status)
{
	setAge(age);
	setExpirience(expirience);
	setName(name);
	setPositionRatings(rating);
	setSalary(sallary);
	setStatus(status);
	setWork(counter);
	setPortfolio(portfolio);
}

bool Designer::setPortfolio(string mail)
{
	if (CheckMail(mail))
	{
		this->portfolio = mail;
		return true;
	}
	return false;
}

bool Designer::setWork(size_t counter)
{
	if (counter >= 0 && counter <= 1000)
	{
		this->counterOfWorks = counter;
		return true;
	}
		return false;
}

void Designer::print()
{
	Worker::print();
	cout << "link to portfolio: " << this->portfolio;
	cout << "Quantity of works: " << this->counterOfWorks;
}
