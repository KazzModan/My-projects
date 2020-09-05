#pragma once
#include "Designer.h"
#include <iostream>
#include <vector>
using namespace std;

class GraphicsDes : protected Designer
{
public:
	bool setbanners(string banner);
	bool setLogos(string logos);
	bool setLoayots(string layots);
	GraphicsDes(size_t counter=0, string portfolio="", string name="", size_t age=0, size_t expirience=0,
		size_t rating=0, size_t sallary=0, Status status=Status::NONE, string works="", string templates="",string layout="",string banner="",string logos="");
	void print();
protected:
	vector <string> logos;
	vector <string> banners;
	vector <string> layouts;
};

