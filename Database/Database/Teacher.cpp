#include <iostream>
#include "Teacher.h"
#include "Lessons.h"
using namespace std;

void CreateNewTeacher(Teacher& teacher, Lessons* lessons, size_t sizeLessons, Teacher* teachers, size_t sizeOfTeacher)//добавление нового учителя
{
	int choose;
	int counter = 0;
	int couterOfErrors = 0;
	do
	{
		int symbCounter = 0;
		couterOfErrors = 0;
		cout << "Enter name of new Teacher: ";
		cin >> teacher.name;
		cout << "Enter surnaname of new teacher: ";
		cin >> teacher.surname;
		cout << "Enter teacher mail: ";
		cin >> teacher.email;
		cout << "Enter Teacher age: ";
		cin >> teacher.age;
		for (size_t i = 0; i < sizeOfTeacher; i++)
		{
			if (strcmp(teacher.name, teachers[i].name) == 0 && strcmp(teacher.surname, teachers[i].surname) == 0)
			{
				cout << "Teacher with similar name has already been in list\n";
				couterOfErrors = 1;
				break;
			}
		}
		for (size_t i = 0; i < strlen(teacher.name); i++)
		{
			if (teacher.name[i] >= 'A' && teacher.name[i] <= 'Z' || teacher.name[i] >= 'a' && teacher.name[i] <= 'z')
				continue;
			else
			{
				cout << "You entered incorrect teacher's name, do it again\n";
				couterOfErrors = 1;
				break;
			}
		}
		for (size_t i = 0; i < strlen(teacher.surname); i++)
		{
			if (teacher.surname[i] >= 'A' && teacher.surname[i] <= 'Z' || teacher.surname[i] >= 'a' && teacher.surname[i] <= 'z')
				continue;
			else
			{
				cout << "You entered incorrect teacher's surname, do it again\n";
				couterOfErrors = 1;
				break;
			}
		}
		for (size_t i = 0; i < strlen(teacher.email); i++)
		{
			if (teacher.email[i] == '@')
				symbCounter++;
			else
				continue;

		}
		if (symbCounter != 1)
		{
			cout << "You entered incorrect teacher's email, do it again\n";
			couterOfErrors = 1;
		}
		if (teacher.age < 18 || teacher.age >= 100)
		{
			cout << "You entered incorrect teacher's age, do it again\n";
			couterOfErrors = 1;
		}
	} while (couterOfErrors != 0);
	cout << "Choose lessons, what you want add\n";
	do//вибор предметов, которые преподаёт учитель
	{
		for (size_t i = 0; i < sizeLessons; i++)
		{
			cout << i + 1 << ":  " << lessons[i].subject << endl;
			cout << "-------------\n";
		}
		cout << "0: exit\n";
		cin >> choose;
		if (choose != 0)
		{
			lessons[choose - 1].quantityOfTeachers++;
			if (counter == 0)
			{
				teacher.lesson = new Lessons[1];
				teacher.lesson[0] = lessons[choose - 1];
				teacher.sizeOfLessons = 1;
				counter++;
			}
			else
			{
				Lessons* oldLesson = new Lessons[teacher.sizeOfLessons];
				for (size_t i = 0; i < teacher.sizeOfLessons; i++)
					oldLesson[i] = teacher.lesson[i];
				delete[]teacher.lesson;
				teacher.lesson = new Lessons[teacher.sizeOfLessons + 1];
				for (size_t i = 0; i < teacher.sizeOfLessons; i++)
					teacher.lesson[i] = oldLesson[i];
				delete[]oldLesson;
				teacher.lesson[teacher.sizeOfLessons] = lessons[choose - 1];
				teacher.sizeOfLessons++;
				counter++;
			}
		}
	} while (choose != 0);
	cin.ignore();
}

void ShowAllteachers(const Teacher* teacher, size_t size)//вывод всех училей на экран
{
	if (teacher == nullptr || size == 0)
	{
		cout << "List is empy\n";
		return;
	}
	for (size_t i = 0; i < size; i++)
	{
		ShowTeacher(teacher[i]);
	}
}

void ShowTeacher(const Teacher& teacher)//вывод одного учителя на экран
{
	cout << "Teacher's name: " << teacher.name << endl;
	cout << "Teacher's surname: " << teacher.surname << endl;
	cout << "Teacher's age: " << teacher.age << endl;
	cout << "Teacher's mail " << teacher.email << endl;
	cout << "His/her lessons: ";
	if (teacher.sizeOfLessons == 0)
	{
		cout << "Teacher dooen`t have a lessons\n";
		cout << "-------------------\n";
		return;
	}
	for (size_t i = 0; i < teacher.sizeOfLessons; i++)
	{
		if (i == teacher.sizeOfLessons - 1)
		{
			cout << teacher.lesson[i].subject << ".";
			continue;
		}
		cout << teacher.lesson[i].subject << ", ";
	}
	cout << endl;
	cout << "-------------------\n";
}
Teacher* AddNewTeacher(Teacher* teacher, size_t& size, const Teacher& nTeacher)//добавление учмтеля в масив учителей
{
	if (teacher == nullptr || size == 0)
	{
		teacher = new Teacher[1];
		teacher[0] = nTeacher;
		size = 1;
		return teacher;
	}
	Teacher* newTeacher = new Teacher[size + 1];
	for (size_t i = 0; i < size; i++)
	{
		newTeacher[i] = teacher[i];
	}
	newTeacher[size] = nTeacher;
	delete[] teacher;
	size++;
	return newTeacher;
}
void SortTeachers(Teacher* teacher, size_t size)//сортировка преподавателей по имени и фамилии
{
	if (teacher == nullptr || size == 0)
	{
		cout << "List is empy\n";
		return;
	}
	for (size_t i = 0; i < size; i++)
	{
		char min[100] = "";
		char minName[100] = "";
		strcpy_s(min, 100, teacher[i].surname);
		strcpy_s(minName, 100, teacher[i].name);
		for (size_t j = i + 1; j < size; j++)
		{
			if (strcmp(min, teacher[j].surname) == 1)
			{
				strcpy_s(min, 100, teacher[i].surname);
				swap(teacher[i], teacher[j]);
			}
			else if (strcmp(min, teacher[j].surname) == 0)
			{
				if (strcmp(minName, teacher[j].name) == 1)
				{
					strcpy_s(minName, 100, teacher[i].name);
					swap(teacher[i], teacher[j]);
				}
			}
		}
	}
}
Teacher* DeleteTeacher(Teacher* teacher, size_t& size, Lessons* lessons, size_t sizeLessons)//удаление учителя из масивов учителей
{
	if (teacher == nullptr || size == 0)
	{
		cout << "List is empy\n";
		return teacher;
	}
	char name[100] = "";
	char surname[100] = "";
	int counter = -1;

	cout << "Enter name of this teacher: ";
	cin >> name;
	cout << "Enter surname of this teacher: ";
	cin >> surname;
	Teacher* newTeacher = new Teacher[size - 1];
	for (size_t i = 0; i < size; i++)
	{
		if (strcmp(name, teacher[i].name) == 0 && strcmp(surname, teacher[i].surname) == 0)
			counter = i;
	}
	if (counter == -1)
	{
		cout << "I didnt find this teacher\n";
		return teacher;
	}
	for (size_t i = 0; i < teacher[counter].sizeOfLessons; i++)
	{
		for (size_t j = 0; j < sizeLessons; j++)
			if (strcmp(teacher[counter].lesson[i].subject, lessons[j].subject) == 0)
				lessons[j].quantityOfTeachers--;
	}
	for (size_t i = 0; i < counter; i++)
	{
		newTeacher[i] = teacher[i];
	}
	for (size_t i = counter = 1; i < size; i++)
	{
		newTeacher[i - 1] = teacher[i];
	}
	delete[] teacher;
	size -= 1;
	return newTeacher;
}
void EditTeacher(Teacher* teacher, size_t size)
{
	if (teacher == nullptr || size == 0)
	{
		cout << "List is empy\n";
		return;
	}
	char name[100] = "";
	char surname[100] = "";
	int count = -1;
	int choose;
	cout << "Enter name of this teacher: ";
	cin >> name;
	cout << "Enter surname of this teacher: ";
	cin >> surname;
	for (size_t i = 0; i < size; i++)
	{
		if (strcmp(name, teacher[i].name) == 0 && strcmp(surname, teacher[i].surname) == 0)
			count = i;
	}
	if (count == -1)
	{
		cout << "I didnt find this teacher\n";
		return;
	}
	cout << "Choose,what you want to edit\n";
	cout << "(1) Teacher's name \n";
	cout << "(2) Teacher's surname\nn ";
	cout << "(3) Teacher's age \n";
	cout << "(4) Teacher's mail\n ";
	cin >> choose;
	switch (choose)
	{
	case 1:
		cout << "Enter new name of this teacher: \n";
		cin >> teacher[count].name;
		break;
	case 2:
		cout << "Enter new surname of this teacher: \n";
		cin >> teacher[count].surname;
		break;
	case 3:
		cout << "Enteer new age of this teacher: \n";
		cin >> teacher[count].age;
		break;
	case 4:
		cout << "Enter new email of this teacher: \n";
		cin >> teacher[count].email;
		break;
	default:
		cout << "Wrong choise\n";
		break;
	}
}
void DeleteDeletedLessons(Teacher* teacher, Lessons* lessons, size_t sizeTeacher, size_t sizeLessons)//удаление удалённого урока и списка уроков, которые преподаёт учитель
{
	int globalCounter = 0;
	int firstCounter = -1;
	int secondCounter = -1;
	do
	{
		for (size_t i = 0; i < sizeTeacher; i++)
		{
			for (size_t j = 0; j < sizeLessons + 1; j++)
			{
				for (size_t k = 0; k < teacher[i].sizeOfLessons; k++)
				{
					if (strcmp(teacher[i].lesson[k].subject, lessons[j].subject) != 0)
					{
						firstCounter = i;
						secondCounter = k;
						break;
					}
				}
			}
		}
		if (secondCounter == -1 && globalCounter == 0 || firstCounter == -1 && globalCounter == 0)
		{
			cout << "Sorry, i didn`t find your lesson";
			return;
		}
		if (secondCounter == -1 && globalCounter == 0 || firstCounter == -1 && globalCounter == 0)
			return;
		Lessons* oldLessonsOfTeacher = new Lessons[teacher[firstCounter].sizeOfLessons];
		for (size_t i = 0; i < sizeTeacher; i++)
		{
			for (size_t j = 0; j < teacher[i].sizeOfLessons; j++)
			{
				if (firstCounter == i)
				{
					oldLessonsOfTeacher[j] = teacher[i].lesson[j];
				}
				else if (firstCounter == i + 1)
					break;
				else
					continue;
			}
		}
		teacher[firstCounter].lesson = new Lessons[teacher[firstCounter].sizeOfLessons - 1];
		for (size_t i = 0; i < sizeTeacher; i++)
		{
			for (size_t j = 0; j < secondCounter; j++)
			{
				if (firstCounter == i)
				{
					teacher[i].lesson[j] = oldLessonsOfTeacher[j];
				}
				else
					continue;
			}
		}
		for (size_t i = 0; i < sizeTeacher; i++)
		{
			for (size_t j = secondCounter + 1; j < teacher[i].sizeOfLessons; j++)
			{
				if (firstCounter == i)
					teacher[i].lesson[j - 1] = oldLessonsOfTeacher[j];
				else
					continue;
			}
		}
		globalCounter++;
		teacher[firstCounter].sizeOfLessons--;
	} while (secondCounter == -1 || firstCounter == -1);
}