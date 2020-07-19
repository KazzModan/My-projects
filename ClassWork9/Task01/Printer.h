#pragma once
#include"Spooler.h"
class Printer
{
public:
	Printer(Spooler spoler);
	void WorkWithDoc();
private:
	Spooler docs;
};