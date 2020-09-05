#pragma once
#include "Pet.h"

class Parrot : protected Pet
{
protected:
	enum class Type
	{
		NONE = 0,
		BLUE_NAPED,
		COCKATIEL,
		CRIMSON_ROSELLA,
		PAPUAN_LORIKEET,
		SCERLET_MASCAW,
		HYACINTH_MACAW,
		KAKAPO,
		BLUE_MACAW,
		PARAKEET,
		BUDGERIGAR,
		ECLECTUS,
		PEACH_FACED_PARAKEET,
		RED_MACAW,
		PALM_CACKATOO,
		RED_LORY,																																		
	};
	Type type;
	size_t weight;
public:

	Parrot();
	Parrot(string name, size_t age, size_t weight, Type type);
	Parrot(string name, size_t age, size_t weight, string sound, Type type);
	bool setType(Type type);
	Type getType() const;
	string getTypeStr() const;
	~Parrot();
};

