#include <iostream>
#include "Teacher.h"
#include "menu.h"
#include "Student.h"
#include "lessons.h";
using namespace std;

int main()
{
	size_t sizeTeacher = 0;
	Teacher* teachers = nullptr;
	Teacher newTeacher;
	size_t sizeStudent = 0;
	Student* students = nullptr;
	Student newStudent;
	int i = 0;
	char choose;
	char checkLog[100];
	char checkPass[10];
	char login[10] = "Demian";
	char password[10] = "4660";
	Lessons* lessons = nullptr;
	Lessons lesson;
	size_t sizeLessons = 0;
	int counter = 0;
	do
	{
		if (counter > 0)
		{
			if (3 - counter == 0)
				cout << "Bye bye\n";
			else
			{
				cout << "Wrong login, or password. Enter thy again\n";
				cout << "You have " << 3 - counter << " attempts\n";
			}
		}
		if (counter > 2)
			return 0;
		cout << "Enter login:\n ";
		cout << "Notice: Login is your name\n";
		cout << "Login: ";
		cin >> checkLog;
		cout << "enter password\n";
		cout << "Notice: password is quantity hours,that you played in dota 2\n";
		cout << "Password: ";
		cin >> checkPass;
		counter++;
	} while (strcmp(login, checkLog) != 0 || strcmp(password, checkPass));
	ClearBuffer();
	cout << "Hello, buddy\n";
	do
	{
		ShowMainMenu();
		cin >> choose;
		ClearBuffer();
		switch (choose)

		{
		case '1':
			do
			{
				ShowTeacherMenu();
				cin >> choose;
				ClearBuffer();
				switch (choose)
				{
				case '1':
					CreateNewTeacher(newTeacher, lessons, sizeLessons,teachers,sizeTeacher);
					teachers = AddNewTeacher(teachers, sizeTeacher, newTeacher);
					break;
				case '2':
					ShowAllteachers(teachers, sizeTeacher);
					break;
				case '3':
					SortTeachers(teachers, sizeTeacher);
					break;
				case '4':
					teachers = DeleteTeacher(teachers, sizeTeacher,lessons,sizeLessons);
					break;
				case '5':
					EditTeacher(teachers, sizeTeacher);
					break;					
				default:
					cout << "Incorrect choose, choose again\n";
					break;
				}
			} while (choose != '9');
			break;
		case '2':
			do
			{
				ShowStudentMenu();
				cin >> choose;
				ClearBuffer();
				switch (choose)
				{
				case '1':
					CreateStudent(newStudent,students,sizeStudent);
					students = AddNewStudent(students, sizeStudent, newStudent);
					break;
				case '2':
					ShowAllStudents(students, sizeStudent);
					break;
				case '3':
					ShowStudentsInCurrectForm(students, sizeStudent);
					break;
				case '4':
					EditStudents(students, sizeStudent);
					break;
				case '5':
					SortStudent(students, sizeStudent);
				case '6':
					DeleteStudent(students, sizeStudent);
					break;
				default:
					break;
				}
			} while (choose != '9');
			break;
		case '3':
			do
			{
				ShowLessonsMenu();
				cin >> choose;
				ClearBuffer();
				switch (choose)
				{
				case '1':
					ShowAllLesson(lessons, sizeLessons);
					break;
				case '2':
					CreateNewLesson(lesson);
					lessons = AddNewLesson(lessons, sizeLessons, lesson);
					break;
				case '3':
					SortLessons(lessons, sizeLessons);
					break;
				case '4':
					lessons = DeleteLesson(lessons, sizeLessons);
					if(sizeTeacher>0)
					DeleteDeletedLessons(teachers, lessons, sizeTeacher, sizeLessons);	
				default:
					break;
				}
			} while (choose != '9');
		case '0':
			cout << "Goodbye, see you next time\n";
			break;
		}
	} while (choose != '0');
	delete[] teachers;
	teachers = nullptr;
	delete[] students;
	students = nullptr;
	delete[] lessons;
	lessons = nullptr;

	return 0;
}