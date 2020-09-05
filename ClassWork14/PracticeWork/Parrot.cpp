#include "Parrot.h"
Parrot::Parrot() : Pet()
{
	this->type = Parrot::Type::NONE;
}

Parrot::Parrot(string name, size_t age, size_t weight, string sound, Type type) : Pet(name, sound, age)
{
	if (!setType(type))
		return;
		this->type = Parrot::Type::NONE;
}
	
Parrot::Parrot(string name, size_t age, size_t weight, Type type) : Pet(name, age)
{
	if (!setType(type))
		return;
}
bool Parrot::setType(Type type)
{
	if (type >= Type::BLUE_MACAW && type <= Type::KAKAPO)
	{
		this->type = type;
		return true;
	}
	return false;
}

Parrot::Type Parrot::getType() const
{
	return this->type;
}

string Parrot::getTypeStr() const
{
	switch (getType())
	{
	case Parrot::Type::NONE:
		return "NONE";
	case Parrot::Type::BLUE_MACAW:
		return "BLUE_MACAW";
	case Parrot::Type::PARAKEET:
		return "PARAKEET";
	case Parrot::Type::BUDGERIGAR:
		return "BUDGERIGAR";
	case Parrot::Type::BLUE_NAPED:
		return "BLUE_NAPED";
	case Parrot::Type::COCKATIEL:
		return "COCKATIEL";
	case Parrot::Type::CRIMSON_ROSELLA:
		return "CRIMSON_ROSELLA";
	case Parrot::Type::ECLECTUS:
		return "ECLECTUS";
	case Parrot::Type::PEACH_FACED_PARAKEET:
		return "PEACH_FACED_PARAKEET";
	case Parrot::Type::RED_MACAW:
		return "RED_MACAW";
	case Parrot::Type::PALM_CACKATOO:
		return "PALM_CACKATOO";
	case Parrot::Type::RED_LORY:
		return "RED_LORY";
	case Parrot::Type::PAPUAN_LORIKEET:
		return "PAPUAN_LORIKEET";
	case Parrot::Type::SCERLET_MASCAW:
		return "SCERLET_MASCAW";
	case Parrot::Type::HYACINTH_MACAW:
		return "HYACINTH_MACAW";
	case Parrot::Type::KAKAPO:   
		return "KAKAPO";
	default:
		return "NONE";
	}
	return "NONE";
}

Parrot::~Parrot()
{

}
