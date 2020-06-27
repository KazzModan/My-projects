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
private:
	string name;
	vector <Archer> arch;
	vector <Barbar> barb;
	vector <Caster> casters;

};

