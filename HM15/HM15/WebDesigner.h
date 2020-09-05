#pragma once
#include "Designer.h"
#include <vector>
class WebDesigner : protected Designer
{
protected:
	vector <string> templates;
	vector <string> workOnFigma;
	public:
		bool setTemplates(string templates);
		bool setWorks(string works);
		WebDesigner(size_t counter = 0, string portfolio = "", string name = "", size_t age = 0,
			size_t expirience = 0, size_t rating = 0, size_t sallary = 0, Status status = Status::NONE, string works="", string templates="");
		void print();
};

