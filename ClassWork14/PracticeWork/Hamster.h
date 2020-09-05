#pragma once
#pragma once
#include "Pet.h"

class Hamster : protected Pet
{
protected:
	enum class Type
	{
		NONE = 0,
		ROBOROVSKY,
		DZUNGARIAN,
		CAMPBELL,
		SUNGURSKY,
		FIELD,
		ORDINARY,
		ANGORA,
	};
	Type type;
public:

	Hamster();
	Hamster(string name, size_t age, Type type);
	Hamster(string name, size_t age, string sound, Type type);
	bool setType(Type type);
	Type getType() const;
	string getTypeStr() const;


};


