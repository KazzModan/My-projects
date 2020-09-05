#include "FrontendDeveloper.h"

Framework::Framework()
{
	this->link = "none";
	this->linkToPreview = "none";
}

Framework::Framework(string link, string linkToPreview)
{
	setLink(link);
	setLinkToPreview(linkToPreview);
}

bool Framework::setLink(string link)
{
	this->link = link;
	return true;
}

bool Framework::setLinkToPreview(string link)
{
	this->linkToPreview = link;
	return true;
}

string Framework::getLink() const
{
	return this->link;
}

string Framework::getLinkToPreview() const
{
	return this->linkToPreview;
}

void Framework::print() const
{
	cout << "link: " << getLink() << endl;
	cout << "link to preview: " << getLinkToPreview() << endl;
}

FrontendDeveloper::FrontendDeveloper() : Developer()
{
	setLink("none");
}

FrontendDeveloper::FrontendDeveloper(const WorkerData& developer, string link) : Developer(developer)
{
	setLink(link);
}

bool FrontendDeveloper::setLink(string link)
{
	this->linkToPortfolio = link;
	return true;
}

string FrontendDeveloper::getLink() const
{
	return this->linkToPortfolio;
}

Framework* FrontendDeveloper::operator[](size_t index)
{
	if (!ch::CheckRangeEnum(index, index, 0, this->listWithFrameworks.size() - 1))
		return nullptr;

	return &this->listWithFrameworks[index];
}

void FrontendDeveloper::addFrameWork(const Framework& framework)
{
	this->listWithFrameworks.push_back(framework);
}

void FrontendDeveloper::removeFrameWork(size_t index)
{
	if (index < 0 || index > this->listWithFrameworks.size() - 1)
		return;
	
	this->listWithFrameworks.erase(this->listWithFrameworks.begin() + index);
}

void FrontendDeveloper::print() const
{
	Developer::print();
	cout << "\nlink porfolio: " << getLink() << "\n\n";

	for (size_t i = 0; i < this->listWithFrameworks.size(); i++)
		this->listWithFrameworks[i].print();
}
