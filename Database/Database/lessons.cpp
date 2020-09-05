#include <iostream>
#include "lessons.h"
#include "Teacher.h"

using namespace std;

void ShowLesson(const Lessons& lessons)//вивод урока
{
	cout << lessons.subject << endl;
	cout << "Quantity teacher, that teach this lesson: " << lessons.quantityOfTeachers << endl;;
	cout << "--------------\n";
}
void ShowAllLesson(Lessons* lessons, size_t size)//вывод всех уроков
{
	if (lessons == nullptr || size == 0)
	{
		cout << "list is empy\n";
		return;
	}
	for (size_t i = 0; i < size; i++)
	{
		ShowLesson(lessons[i]);
	}
}
void CreateNewLesson(Lessons& lesson)//добавление нового урока
{
		cout << "Enter new lesson: ";
		cin >> lesson.subject;
}

Lessons* AddNewLesson(Lessons* lessons, size_t& size, const Lessons& lesson)//запись нового урока массив уроков
{
	if (lessons == nullptr || size == 0)
	{
		lessons = new Lessons[1];
		size = 1;
		lessons[0] = lesson;
		return lessons;
	}
	for (size_t i = 0; i < size; i++)
	{
		if (strcmp(lessons[i].subject, lesson.subject) == 0)
		{
			cout << "Lesson with similar name had already in the list\n";
			return lessons;
		}
	}
	Lessons* newLessons = new Lessons[size + 1];
	for (size_t i = 0; i < size; i++)
		newLessons[i] = lessons[i];
	newLessons[size] = lesson;
	size++;

	return newLessons;
}

void SortLessons(Lessons* lessons, size_t size)//сортировка уроков
{
	if (lessons == nullptr || size == 0)
	{
		cout << "list is empy\n";
		return;
	}
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = i + 1; j < size; j++)
		{
			if (strcmp(lessons[i].subject, lessons[j].subject) == 1)
				swap(lessons[i], lessons[j]);
		}
	}
}
Lessons* DeleteLesson(Lessons* lessons, size_t& size)//удаление урока
{
	int counter = -1;
	char delLesson[30] = "";
	if (lessons == nullptr || size == 0)
	{
		cout << "list is empy\n";
		return lessons;
	}
	cout << "Enter lesson, which you want delete:  ";
	cin >> delLesson;
	for (size_t i = 0; i < size; i++)
	{
		if (strcmp(lessons[i].subject, delLesson) == 0)
			counter = i;
	}
	if (counter == -1)
	{
		cout << "I didnt find this lesson\n";
		return lessons;
	}
	Lessons* newLessons = new Lessons[size - 1];
	for (size_t i = 0; i < counter; i++)
		newLessons[i] = lessons[i];
	for (size_t i = counter + 1; i < size; i++)
		newLessons[i - 1] = lessons[i];
	size--;

	return newLessons;
}
