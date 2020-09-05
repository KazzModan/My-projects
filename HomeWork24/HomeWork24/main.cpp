#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;
void ShowText(FILE* file, size_t size, char line[]);
void ShowMenu();
void DeleteWord(FILE* file, size_t size, char line[]);
int main()
{

	int const SIZE = 100;
	char line[SIZE];
	FILE* file;
	int choose = 0;
	ShowMenu();
	scanf_s("%d", &choose);
	switch (choose)
	{
	case 1:
		if (!(file = fopen("Text.txt", "r")))
		{
			printf("sorry,i can't open file\n");
			return 1;
		}
		ShowText(file, SIZE, line);
		if (fclose(file))
		{
			printf("sorry, i can't close file\n");
			return 2;
		}
		break;
	}
	return 0;
}

void ShowText(FILE* file, size_t size, char line[])
{

	while (fgets(line, size, file))
		printf("%s", line);

}
void ShowMenu()
{
	printf("Choose, what you want to do\n");
	printf("(1) Read text from file\n");
}

void DeleteWord(FILE* file, size_t size, char line[])
{
	const int SIZE = 30;
	char word[SIZE];
	printf("Enter symbol what you want delete\n");
	scanf_s("%s", word);
	size_t sizeWord = strlen(word);
	size = size - strlen(word);
	size_t sizeBefore = strstr(line, word);

}
