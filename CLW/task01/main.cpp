#include <iostream>
#include "Header.h"
using namespace std;

int main()
{
	SList<int> list;
	list.addOnFirst(1);
	list.addOnFirst(2);
	list.addOnLast(3);
	list.print();
	list.DeleteAll();



	return 0;
}