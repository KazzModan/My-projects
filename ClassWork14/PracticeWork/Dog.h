#pragma once
#include "Pet.h"

class Dog : protected Pet
{
protected:
	enum class Type
	{
		NONE = 0,
		SHEPHERD,
		AKITA,
		HUSKY,
		ALASKAN,
		ESKIMO,
		FOXHOUND
	};
	Type type;

public:
	
	Dog();
	Dog(string name, size_t age, Type type);
	Dog(string name, size_t age, string sound, Type type);

	bool setType(Type type);

	Type getType() const;
	string getTypeStr() const;
	~Dog();

	
};

