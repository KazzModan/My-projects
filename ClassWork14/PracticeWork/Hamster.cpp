#include "Hamster.h"

Hamster::Hamster() : Pet()
{
	this->type = Hamster::Type::NONE;
}

Hamster::Hamster(string name, size_t age, string sound, Type type) : Pet(name, sound, age)
{
	if (!setType(type))
		return;
	else
		this->type = Hamster::Type::NONE;
}

Hamster::Hamster(string name, size_t age, Type type) : Pet(name, age)
{
	this->type = Hamster::Type::NONE;
}

bool Hamster::setType(Type type)
{
	if (type >= Type::DZUNGARIAN && type <= Type::SUNGURSKY)
	{
		this->type = type;
		return true;
	}
	return false;
}

Hamster::Type Hamster::getType() const
{
	return this->type;
}

string Hamster::getTypeStr() const
{
	switch (getType())
	{
	case Hamster::Type::NONE:
		return "NONE";
	case Hamster::Type::DZUNGARIAN:
		return "DZUNGARIAN";
	case Hamster::Type::FIELD:
		return "FIELD";
	case Hamster::Type::ORDINARY:
		return "ORDINARY";
	case Hamster::Type::ANGORA:
		return "ANGORA";
	case Hamster::Type::CAMPBELL:
		return "CAMPBELL";
	case Hamster::Type::ROBOROVSKY:
		return "ROBOROVSKY";
	case Hamster::Type::SUNGURSKY:
		return "SUNGURSKY";
	default:
		return "NONE";
	}
	return "NONE";
}


