#pragma once
class Unit
{
public:
	enum Type
	{
		NONE, BARBAR, MAGE, ARCHER
	};
	void setHp(size_t hp);
	void setDmg(size_t hp);
	void setDodge(size_t hp);
	void setType(Type type);
	enum Limits
	{
		MIN = 0, MAX = 100
	};
	Unit(size_t hp, size_t dmg, size_t dodge, Type type);
	size_t getHp() const;
protected:
	size_t hp;
	size_t dmg;
	size_t chanceToDodge;
	Type type;
	
};

