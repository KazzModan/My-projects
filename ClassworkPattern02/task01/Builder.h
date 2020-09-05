#pragma once
#include "Doc.h"
#include <iostream>
class Builder abstract
{
public:
	Builder();
	virtual void setHeader() = 0;
	virtual void setContent() = 0;
	virtual void setEtc() = 0;
	Doc* getDoc();
	~Builder();
	Doc* document;

};

