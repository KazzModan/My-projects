#include "lessons.h"
#pragma once
struct Teacher
{
	char name[100] = "";
	char surname[100] = "";
	int age;
	char email[100] = "";
	int sizeOfLessons=0;
	Lessons* lesson;
};
void CreateNewTeacher(Teacher& teacher, Lessons* lessons, size_t sizeLessons, Teacher* teachers, size_t sizeOfTeacher);
Teacher* AddNewTeacher(Teacher* teacher, size_t& size, const Teacher& newTeacher);
void ShowTeacher(const Teacher& teacher);
void ShowAllteachers(const Teacher* teacher, size_t size);
void SortTeachers(Teacher* teacher, size_t size);
void EditTeacher(Teacher* teeacher, size_t size);
Teacher* DeleteTeacher(Teacher* teacher, size_t& size, Lessons* lessons, size_t sizeLessons);
void DeleteDeletedLessons(Teacher* teacher, Lessons* lessons, size_t sizeTeacher, size_t sizeLessons);
