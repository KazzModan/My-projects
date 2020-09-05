#pragma once
#include "Developer.h"

class BackendDeveloper : protected Developer
{
public:
	BackendDeveloper();
	BackendDeveloper(const WorkerData& developer, string linkToProjects = "none");

	/*setters*/

	bool setLinkToProjects(string link);

	/*getters*/

	string getLinkToProjects() const;

	/*others*/

	void addLenguage(string lenguage);
	void addCustomer(string customer);

	void print() const;

protected:
	vector<string> listWithLenguages;
	vector<string> listWithCustomers;
	string linkToProjects;
};