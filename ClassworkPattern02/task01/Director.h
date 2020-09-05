#pragma once
#include "Builder.h"
class Director
{
	Builder* build;
public:
	Director();
	Director(Builder* build);
	Doc* Create();
};

