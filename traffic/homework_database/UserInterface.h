#pragma once
#include "TemplateTree.h"
#include "CarData.h"
#include "Enter.h"

class UserInterface
{
public:

	static void Menu();

private:

	static void ShowMenu();
	static void AddOffense(TemplateTree<CarData>& database);
	static bool FindCar(TemplateTree<CarData>& database);
	static void MultipleFind(TemplateTree<CarData>& database);
};

