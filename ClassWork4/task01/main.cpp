#include <iostream>
#include "Employee.h"

using namespace std;

int main()
{
	Employee User("Petya", 1020, 40, Employee::TESTER);
	Employee User2("Vasua", 1100, 33, Employee::TESTER);
	User.print();
	User2.print();
	cout << Employee::getCounter() << endl;
	Employee::cmp(User, User2);
}