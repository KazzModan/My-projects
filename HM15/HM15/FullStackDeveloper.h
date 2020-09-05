#pragma once
#include "FrontendDeveloper.h"
#include "BackendDeveloper.h"

class FullStackDeveloper : protected FrontendDeveloper, protected BackendDeveloper
{
public:
	FullStackDeveloper();
	FullStackDeveloper(const WorkerData& worker, string linkToPortfolio, string linkToProjects);
	void print() const;
};