#include "Cat.h"
Cat::Cat() : Pet()
{
	this->type = Cat::Type::NONE;
}

Cat::Cat(string name, size_t age, string sound, Type type) : Pet(name, sound, age)
{
	if (!setType(type))
		return;
	else
		this->type = Cat::Type::NONE;
}

Cat::Cat(string name, size_t age, Type type) : Pet(name, age)
{
	this->type = Cat::Type::NONE;
}

bool Cat::setType(Type type)
{
	if (type >= Type::WIREHAIR && type <= Type::ABYSSINIAN)
	{
		this->type = type;
		return true;
	}
	return false;
}

Cat::Type Cat::getType() const
{
	return this->type;
}

string Cat::getTypeStr() const
{
	switch (getType())
	{
	case Cat::Type::NONE:
		return "NONE";
	case Cat::Type::WIREHAIR:
		return "WIREHAIR";
	case Cat::Type::SHORTHAIR:
		return "SHORTHAIR";
	case Cat::Type::BOMBAY:
		return "BOMBAY";
	case Cat::Type::BENGAL:
		return "BENGAL";
	case Cat::Type::BIRMAN:
		return "BIRMAN";
	case Cat::Type::BURMESE:
		return "BURMESE";
	case Cat::Type::CURL:
		return "CURL";
	case Cat::Type::ABYSSINIAN:
		return "ABYSSINIAN";
	default:
		return "NONE";
	}

	return "NONE";
}

Cat::~Cat()
{

}
