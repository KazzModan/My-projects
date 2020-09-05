#include <iostream>
#include "Student.h"
#define FORM_CHECK (student.form[0] < '1' || student.form[0] > '9' || student.form[1] != '-' || student.form[2] < 'A' || student.form[2]>'Z') && (student.form[0] != '1' || student.form[1] < '0' || student.form[1] > '1' || student.form[2] != '-' || student.form[3] < 'A' || student.form[3] > 'Z') //макрос проверки класса студента
#define STUDENT_PHONE_CHECK student.phNumberStudent[0] != '+' || student.phNumberStudent[1] != '3' || student.phNumberStudent[2] != '8' || student.phNumberStudent[3] != '0' || strlen(student.phNumberStudent) != 13 //макрос проверки номера телефона студента
#define PARENTS_PHONE_CHECK student.phNumbParents[0] != '+' || student.phNumbParents[1] != '3' || student.phNumbParents[2] != '8' || student.phNumbParents[3] != '0' || strlen(student.phNumbParents) != 13 //макрос проверки номера телефона его родителей
using namespace std;

void CreateStudent(Student& student, Student* students, size_t sizeOfStudent) //добавление нового студента
{
	int couterOfErrors = 0;
	do
	{
		couterOfErrors = 0;
		cout << "Enter student's name: ";
		cin >> student.name;
		cout << "Enter student's surname: ";
		cin >> student.surname;
		cout << "Enter student's form (number-LETTER): ";
		cin >> student.form;
		cout << "Enter studet's phone number: ";
		cin >> student.phNumberStudent;
		cout << "Enter phone number of his/her parents: ";
		cin >> student.phNumbParents;
		cout << "Enter student's email: ";
		cin >> student.email;
		int symbCounter = 0;
		for (size_t i = 0; i < sizeOfStudent; i++)
		{
			if (strcmp(student.name, students[i].name) == 0 && strcmp(student.surname, students[i].surname) == 0)
			{
				cout << "Student with similar name has already been in list\n";
				couterOfErrors = 1;
				break;
			}
		}
		for (size_t i = 0; i < strlen(student.name); i++)
		{
			if (student.name[i] >= 'A' && student.name[i] <= 'Z' || student.name[i] >= 'a' && student.name[i] <= 'z')
				continue;
			else
			{
				cout << "You entered incorrect teacher's name, do it again\n";
				couterOfErrors = 1;
				break;
			}
		}
		for (size_t i = 0; i < strlen(student.surname); i++)
		{
			if (student.surname[i] >= 'A' && student.surname[i] <= 'Z' || student.surname[i] >= 'a' && student.surname[i] <= 'z')
				continue;
			else
			{
				cout << "You entered incorrect student's surname, do it again\n";
				couterOfErrors = 1;
				break;
			}
		}
		for (size_t i = 0; i < strlen(student.email); i++)
		{
			if (student.email[i] == '@')
				symbCounter++;
			else
				continue;
		}
		if (symbCounter != 1)
		{
			cout << "You entered incorrect students's email, do it again\n";
			couterOfErrors = 1;
		}
		if (FORM_CHECK)
		{
			cout << "You entered incorrect student's form, do it again\n";
			couterOfErrors = 1;
		}
		if (STUDENT_PHONE_CHECK)
		{
			cout << "You entered incorrect student's phone number, do it again\n";
			couterOfErrors = 1;
		}
		if (PARENTS_PHONE_CHECK)
		{
			cout << "You entered incorrect parents's phone number, do it again\n";
			couterOfErrors = 1;
		}
	} while (couterOfErrors != 0);
}
Student* AddNewStudent(Student* student, size_t& size, const Student& newStudent) //запись нового студента в массив студентов
{
	if (student == nullptr || size == 0)
	{
		student = new Student[1];
		student[0] = newStudent;
		size = 1;
		return student;
	}
	Student* nStudent = new Student[size + 1];
	for (size_t i = 0; i < size; i++)
	{
		nStudent[i] = student[i];
	}
	nStudent[size] = newStudent;
	size++;
	return nStudent;
}
void ShowStudent(const Student& student)// вывод одного студента на экран
{
	cout << "Student's name: " << student.name << endl;
	cout << "Student's surname: " << student.surname << endl;
	cout << "Student's form:  " << student.form << endl;
	cout << "Student's phone number: " << student.phNumberStudent << endl;
	cout << "His/her parents phone number: " << student.phNumbParents << endl;
	cout << "Student's mail: " << student.email << endl;
	cout << "-------------------------------\n";
}
void ShowAllStudents(const Student* student, size_t size)// вывод всех студентов на экран
{
	if (size == 0 || student == nullptr)
	{
		cout << "List is empy\n";
		return;
	}
	for (size_t i = 0; i < size; i++)
	{
		ShowStudent(student[i]);
	}
}
void ShowStudentsInCurrectForm(const Student* student, size_t size)//Вывод студентов в определённом классе
{
	if (size == 0 || student == nullptr)
	{
		cout << "List is empy\n";
		return;
	}
	char form[100] = "";
	cout << "Enter name of form,what you want see (number-LETTER): ";
	cin >> form;
	for (size_t i = 0; i < size; i++)
	{
		if (strcmp(form, student[i].form) == 0)
			ShowStudent(student[i]);
	}
}
void EditStudents(Student* student, size_t size)//изменение определённого пункта студента
{
	char name[100] = "";
	char surname[100] = "";
	int count = -1;
	int choose;
	cout << "Enter name of student,which you want edit: ";
	cin >> name;
	cout << "Enter surname of student, which you want edit: ";
	cin >> surname;
	for (size_t i = 0; i < size; i++)
	{
		if (strcmp(name, student[i].name) == 0 && strcmp(surname, student[i].surname) == 0)
		{
			count = i;
		}
	}
	if (count == -1)
	{
		cout << "Sorry,i did't find this student\n";
		return;
	}
	cout << "    Choose, what you want edit\n";
	cout << "(1) Student's name:\n ";
	cout << "(2) Student's surname: \n";
	cout << "(3) Student's form: \n";
	cout << "(4) Student's phone number: \n";
	cout << "(5) His/her parents phone number: \n";
	cout << "(6) Student's mail: \n";
	cin >> choose;
	switch (choose)
	{
	case 1:
		cout << "Enter new name: ";
		cin >> student[count].name;
		break;
	case 2:
		cout << "Enter new surname: ";
		cin >> student[count].surname;
		break;
	case 3:
		cout << "Enter new form: ";
		cin >> student[count].form;
		break;
	case 4:
		cout << "Enter new phone number: ";
		cin >> student[count].phNumberStudent;
		break;
	case 5:
		cout << "Enter new parent's phone number: ";
		cin >> student[count].phNumbParents;
		break;
	case 6:
		cout << "Enter new student's mail: ";
		cin >> student[count].email;
		break;
	default:
		cout << "Whrong choise: \n";
		break;
	}
}
void SortStudent(Student* student, size_t size)//сортировка студентов по имени и фамилие в каждом классе
{
	if (size == 0 || student == nullptr)
	{
		cout << "List is empy\n";
		return;
	}
	int count = 0;
	int secCount = 0;
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = i + 1; j < size; j++)
		{
			if (strcmp(student[i].form, student[j].form) == 1)
			{
				swap(student[i], student[j]);
			}
		}
	}
	while (count < size)
	{
		for (size_t i = count + 1; i < size; i++)
		{
			if (strcmp(student[count].form, student[i].form) == 0)
				count++;
		}
		for (size_t i = secCount; i < count + 1; i++, secCount++)
		{
			for (size_t j = i + 1; j < count + 1; j++)
			{
				if (strcmp(student[i].surname, student[j].surname) == 1)
				{
					swap(student[i], student[j]);
				}
				else if (strcmp(student[i].surname, student[j].surname) == 1)
				{
					if (strcmp(student[i].name, student[j].name) == 1)
						swap(student[i], student[j]);
				}
			}
		}
		count++;
	}
}
Student* DeleteStudent(Student* student, size_t& size)//удаление студента из массива студентов
{
	if (student == nullptr || size == 0)
	{
		cout << "List is empy\n";
		return student;
	}
	char name[100] = "";
	char surname[100] = "";
	int count = -1;

	cout << "Enter name of this student: ";
	cin >> name;
	cout << "Enter surname of this student: ";
	cin >> surname;
	Student* newStudent = new Student[size - 1];
	for (size_t i = 0; i < size; i++)
	{
		if (strcmp(name, student[i].name) && strcmp(surname, student[i].surname))
			count = i;
	}
	if (count == -1)
	{
		cout << "I didnt find this student\n";
		return student;
	}
	for (size_t i = 0; i < count; i++)
	{
		newStudent[i] = student[i];
	}
	for (size_t i = count = 1; i < size; i++)
	{
		newStudent[i - 1] = student[i];
	}
	delete[] student;
	size -= 1;
	return newStudent;
}