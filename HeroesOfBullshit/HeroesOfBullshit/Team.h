#pragma once
#include <vector>
#include "Archer.h"
#include "Barbar.h"
#include "Caster.h"
#include <iostream>
using namespace std;
class Team
{
public:
	void setName(string name);
	void AddArcher(Archer archer);
	void AddBarbar(Barbar bard);
	void AddCaster(Caster cast);
	void Check();
	Archer getArc() const { return this->arch[0];}
	Barbar getBarb() const { return this->barb[0];}
	Caster getCast() const { return this->casters[0];}
	void print();
private:
	string name;
	vector <Archer> arch;
	vector <Barbar> barb;
	vector <Caster> casters;

};

