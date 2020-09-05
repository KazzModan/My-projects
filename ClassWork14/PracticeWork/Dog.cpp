#include "Dog.h"

Dog::Dog() : Pet()
{
	this->type = Dog::Type::NONE;
}

Dog::Dog(string name, size_t age, string sound, Type type) : Pet(name, sound, age)
{
	if (!setType(type))
		return;
	else
		this->type = Dog::Type::NONE;
}

Dog::Dog(string name, size_t age, Type type) : Pet(name, age)
{
	this->type = Dog::Type::NONE;
}

bool Dog::setType(Type type)
{
	if (type >= Type::SHEPHERD && type <= Type::FOXHOUND)
	{
		this->type = type;
		return true;
	}
	return false;
}

Dog::Type Dog::getType() const
{
	return this->type;
}

string Dog::getTypeStr() const
{
	switch (getType())
	{
	case Dog::Type::SHEPHERD:
		return "SHEPHERD";
	case Dog::Type::AKITA:
		return "AKITA";
	case Dog::Type::HUSKY:
		return "HUSKY";
	case Dog::Type::ALASKAN:
		return "ALASKAN";
	case Dog::Type::ESKIMO:
		return "ESKIMO";
	case Dog::Type::FOXHOUND:
		return "FOXHOUND";
	default:
		return "NONE";
	}
	return "NONE";
}

Dog::~Dog()
{

}
