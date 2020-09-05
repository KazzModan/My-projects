#include "BackendDeveloper.h"

BackendDeveloper::BackendDeveloper() : Developer()
{
	//clear
}

BackendDeveloper::BackendDeveloper(const WorkerData& developer, string linkToProjects) : Developer(developer)
{
	setLinkToProjects(linkToProjects);
}

bool BackendDeveloper::setLinkToProjects(string link)
{
	if (link.empty())
		return false;

	this->linkToProjects = link;
	return true;
}

string BackendDeveloper::getLinkToProjects() const
{
	return this->linkToProjects;
}

void BackendDeveloper::addLenguage(string lenguage)
{
	this->listWithLenguages.push_back(lenguage);
}

void BackendDeveloper::addCustomer(string customer)
{
	this->listWithCustomers.push_back(customer);
}

void BackendDeveloper::print() const
{
	Developer::print();
	
	for (size_t i = 0; i < this->listWithLenguages.size(); i++)
		cout << "lenguage: " << this->listWithLenguages[i] << endl;

	for (size_t i = 0; i < this->listWithCustomers.size(); i++)
		cout << "customer: " << this->listWithCustomers[i] << endl;

	cout << "link to projects: " << getLinkToProjects() << endl;
}
