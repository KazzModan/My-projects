#include "FullStackDeveloper.h"

FullStackDeveloper::FullStackDeveloper() : FrontendDeveloper(), BackendDeveloper()
{
	//clear
}

FullStackDeveloper::FullStackDeveloper(const WorkerData& worker, string linkToPortfolio, string linkToProjects) : FrontendDeveloper(worker, linkToPortfolio), BackendDeveloper(worker, linkToProjects)
{
	//clear
}

void FullStackDeveloper::print() const
{
	FrontendDeveloper::print();
	BackendDeveloper::print();
}
