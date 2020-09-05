#pragma once
#include "worker.h"
#include <vector>
using std::vector;

class Technologie
{
public:
	Technologie();

	/*setters*/

	bool setTitle(string title);
	bool setDescription(string description);

	/*getters*/

	string getTitle() const;
	string getDescription() const;

	//show
	void print() const;

protected:
	string title;
	string description;
};

class Developer : protected Worker
{
public:
	Developer();
	Developer(const WorkerData& worker);

	void addTechnologie(Technologie tech);
	size_t getQuentityOfWorks() const;

	void print() const;

protected:
	vector<Technologie> listWithTechologies;
};

