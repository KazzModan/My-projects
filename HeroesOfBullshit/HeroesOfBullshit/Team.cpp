#include "Team.h"
#include "Checks.h"
void Team::setName(string name)
{
	if(CheckPeopleName(name))
	this->name = name;
}

void Team::AddArcher(Archer archer)
{
	this->arch.push_back(archer);
}

void Team::AddBarbar(Barbar bard)
{
	this->barb.push_back(bard);

}
void Team::Check()
{
	auto aIter = arch.begin();
	auto bIter = barb.begin();
	auto cIter = casters.begin();


	for (size_t i = 0; i < arch.size(); i++)
	{
		if (arch[i].getHp() <= 0)
			arch.erase(aIter);
		++aIter;
	}
	for (size_t i = 0; i < barb.size(); i++)
	{
		if (arch[i].getHp() <= 0)
			barb.erase(bIter);
		++bIter;
	}
	for (size_t i = 0; i < barb.size(); i++)
	{
		if (arch[i].getHp() <= 0)
			casters.erase(cIter);
		++cIter;
	}
}
void Team::print()
{
	cout << "---" << this->name<<"---" << endl;
	this->arch[0].print();
	this->barb[0].print();
	this->casters[0].print();
}
void Team::AddCaster(Caster cast)
{
	this->casters.push_back(cast);
}
