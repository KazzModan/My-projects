#pragma once
#include "Developer.h"

class Framework
{
public:
	Framework();
	Framework(string link = "none", string linkToPreview = "none");

	/*setters*/

	bool setLink(string link);
	bool setLinkToPreview(string link);

	/*getters*/

	string getLink() const;
	string getLinkToPreview() const;

	//show
	void print() const;

private:
	string link;
	string linkToPreview;

};

class FrontendDeveloper : protected Developer
{
public:
	FrontendDeveloper();
	FrontendDeveloper(const WorkerData& developer, string link = "none");

	/*setters*/

	bool setLink(string link);

	/*getters*/

	string getLink() const;

	/*operators*/

	Framework* operator [] (size_t index);

	/*other*/

	void addFrameWork(const Framework& framework);
	void removeFrameWork(size_t index);

	void print() const;

protected:
	vector<Framework> listWithFrameworks;
	string linkToPortfolio;

};