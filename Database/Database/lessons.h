#pragma once
struct Lessons
{
	char subject[30];
	int quantityOfTeachers=0;
};
void ShowLesson(const Lessons& lessons);
void ShowAllLesson( Lessons* lessons, size_t size);
Lessons* AddNewLesson(Lessons* lessons, size_t& size, const Lessons& lesson);
void CreateNewLesson(Lessons& lesson);
void SortLessons(Lessons* lessons, size_t size);
Lessons* DeleteLesson(Lessons* lessons, size_t& size);