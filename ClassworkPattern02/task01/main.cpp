#include <iostream>
#include "DocBuilder.h"
#include "Director.h"
int main()
{
	DocBuilder builder;
	Director* director;
	size_t choose;
	do
	{
	cout << "1: doc , 2 HTML doc, 0: exit\n";
	std::cin >> choose;
	switch (choose)
	{
	case 1:
	 director = new Director(&builder);
		director->Create()->Show();
		delete director;
		break;
	case 2:
		director = new Director(new HTMLBuilder);
		director->Create()->Show();
		delete director;
		break;
	case 0: 
		cout << "bb\n";
		break;
	default:
		cout << "Wrong choise\n";
		break;
	}
	}while (choose != 0);

	return 0;
}