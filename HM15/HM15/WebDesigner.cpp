#include "WebDesigner.h"

bool WebDesigner::setTemplates(string templates)
{
	if (CheckLettersAndNumbers(templates))
	{
		this->templates.push_back(templates);	
		return true;
	}
	return false;
}

bool WebDesigner::setWorks(string works)
{
	if (CheckLettersAndNumbers(works))
	{
		this->workOnFigma.push_back(works);
		return true;
	}
	return false;

}

WebDesigner::WebDesigner(size_t counter, string portfolio, string name, size_t age, size_t expirience,
	size_t rating, size_t sallary, Status status,string works,string templates) :Designer(counterOfWorks, portfolio,name,age,expirience,positionRatings,salary,status)
{
	setAge(age);
	setName(name);
	setExpirience(expirience);
	setPositionRatings(rating);
	setSalary(sallary);
	setStatus(status);
	setPortfolio(portfolio);
	setWork(counter);
	setWorks(works);
	setTemplates(templates);
}

void WebDesigner::print()
{
	Designer::print();
}
