#include <iostream>
#include "menu.h"
//функции для вывода различных меню
using namespace std;
void ShowTeacherMenu()
{
	cout << "(1) Add new teacher\n";
	cout << "(2) Show all teachers\n";
	cout << "(3) Sort teachets by surname\n";
	cout << "(4) Delete teacher\n";
	cout << "(5) Edit teacher\n";
	cout << "(9) Exit\n";
}
void ShowMainMenu()
{
	cout << "What do you want?\n";
	cout << "(1) Work with teachers\n";
	cout << "(2) Work with students\n";
	cout << "(3) Work with lessons\n";
	cout << "(0) Exit\n";
}
void ClearBuffer()//проверка на правильность ввода
{
	system("cls");
	while (cin.get() != '\n')
		continue;
}
void ShowStudentMenu()
{
	cout << "(1) Add new student\n";
	cout << "(2) Show all students\n";
	cout << "(3) Show students in the currect form\n";
	cout << "(4) Edit student\n";
	cout << "(5) Sort students\n";
	cout << "(6) Delete Student\n";
	cout << "(9) Exit\n";
}
void ShowLessonsMenu()
{
	cout << "(1) Show all lessons\n";
	cout << "(2) Add new lesson\n";
	cout << "(3) Sort lessons\n";
	cout << "(4) Delete lesson\n";
	cout << "(9) Exit\n";
}