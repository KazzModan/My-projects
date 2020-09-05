#pragma once
#include "Pet.h"

class Cat : protected Pet
{
protected:
	enum class Type
	{
		NONE = 0,
		WIREHAIR,
		SHORTHAIR,
		CURL,
		ABYSSINIAN,
		BOMBAY,
		BENGAL,
		BIRMAN,
		BURMESE,
	};
	Type type;

public:

	Cat();
	Cat(string name, size_t age, Type type);
	Cat(string name, size_t age, string sound, Type type);
	bool setType(Type type);
	Type getType() const;
	string getTypeStr() const;
	~Cat();
};
