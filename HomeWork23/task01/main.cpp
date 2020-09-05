#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

FILE* OpenFile(char fileName[], char mode[]);
void CloseFile(FILE* file);
void Menu(FILE* file, char fileName[], char mode[]);
void ShowFile(FILE* file, char fileName[], char mode[]);
void AddText(FILE* file, char fileName[], char mode[]);
void FindWord(FILE* file, char fileName[], char mode[]);
void DeleteWord(FILE* file, char fileName[], char mode[]);

int main()
{
	char nameOfFile[] = "text.txt";
	char mode[] = "a+";
	FILE* file = OpenFile(nameOfFile, mode);

	Menu(file, nameOfFile, mode);

	CloseFile(file);
	return 0;
}

FILE* OpenFile(char fileName[], char mode[])
{
	FILE* file;
	if (!(file = fopen(fileName, mode)))
	{
		printf("Error! File not opened!\n");
		exit(1);
	}
	else
		return file;
}

void CloseFile(FILE* file)
{
	if (fclose(file))
	{
		printf("Error! File not closed!\n");
		exit(2);
	}
}

void Menu(FILE* file, char fileName[], char mode[])
{
	bool exit = false;
	int choice;
	do
	{
		printf("(1) Show the file\n");
		printf("(2) Delete word from the file\n");
		printf("(3) Add text to the file\n");
		printf("(4) Find word in the file\n");
		printf("(0) Exit\n");

		printf("Enter: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 0:
			system("cls");
			printf("Bye");
			exit = true;
			break;

		case 1:
			system("cls");
			ShowFile(file, fileName, mode);
			system("pause");
			system("cls");
			break;

		case 2:
			system("cls");
			DeleteWord(file, fileName, mode);
			system("cls");
			break;

		case 3:
			system("cls");
			AddText(file, fileName, mode);
			system("cls");
			break;

		case 4:
			system("cls");
			FindWord(file, fileName, mode);
			system("pause");
			system("cls");
			break;

		default:
			system("cls");
			printf("Error!\n");
			system("pause");
			system("cls");
			break;
		}
	} while (!exit);
}

void ShowFile(FILE* file, char fileName[], char mode[])
{
	char symbol;
	while ((symbol = fgetc(file)) != EOF)
		printf("%c", symbol);

	CloseFile(file);
	file = OpenFile(fileName, mode);
}

void AddText(FILE* file, char fileName[], char mode[])
{
	const int MAXLEN = 128;
	int iteration = 0;
	char temp[MAXLEN] = " ";
	char str[MAXLEN] = " ";
	char end[] = "\\end";
	printf("Enter your text, when you done enter \\end:\n");
	do
	{
		if (strcmp(temp, " "))
		{
			if (iteration != 0)
				strncat_s(str, " ", 1);
			strncat_s(str, temp, strlen(temp));
		}
		scanf("%s", temp);
		iteration++;
	} while (strcmp(temp, end));

	fputs(str, file);
	CloseFile(file);
	file = OpenFile(fileName, mode);
}

void FindWord(FILE* file, char fileName[], char mode[])
{
	const int MAXSIZE = 128;
	char wordTemp[MAXSIZE] = " ";
	char word[MAXSIZE];
	char symbol;
	int count = 0;

	printf("Enter word: ");
	scanf("%s", word);

	for (int i = 0; (symbol = fgetc(file)) != EOF; i++)
	{
		if (symbol == ' ' || symbol == '\n' || symbol == '!'
			|| symbol == '?' || symbol == ':' || symbol == ';'
			|| symbol == '.' || symbol == ',')
		{
			if (!strcmp(word, wordTemp))
			{
				count++;
				for (size_t i = 0; i < strlen(wordTemp); i++)
					wordTemp[i] = ' ';
				i = -1;
			}
			else
			{
				for (size_t i = 0; i < strlen(wordTemp); i++)
					wordTemp[i] = ' ';
				i = -1;
			}
		}
		else
			wordTemp[i] = symbol;
	}
	printf("\n Find result: %d\n", count);

	CloseFile(file);
	file = OpenFile(fileName, mode);
}

void DeleteWord(FILE* file, char fileName[], char mode[])
{
	const int SIZE = 128;
	char tempName[] = "temp.txt";
	char tempMode[] = "w+";
	char wordTemp[SIZE] = " ";
	char word[SIZE];

	printf("Enter word: ");
	scanf("%s", word);

	FILE* temp = OpenFile(tempName, tempMode);

	char symbol;
	while ((symbol = fgetc(file)) != EOF)
		fputc(symbol, temp);

	CloseFile(file);
	file = OpenFile(fileName, tempMode);

	CloseFile(temp);
	temp = OpenFile(tempName, mode);

	for (int i = 0; (symbol = fgetc(temp)) != EOF; i++)
	{
		if (symbol == ' ' || symbol == '\n' || symbol == '!'
			|| symbol == '?' || symbol == ':' || symbol == ';'
			|| symbol == '.' || symbol == ',')
		{
			if (strcmp(word, wordTemp))
			{
				fputs(wordTemp, file);
				fputc(symbol, file);
				for (size_t i = 0; i < strlen(wordTemp); i++)
					wordTemp[i] = ' ';
				i = -1;
			}
			else
			{
				fputc(symbol, file);
				for (size_t i = 0; i < strlen(wordTemp); i++)
					wordTemp[i] = ' ';
				i = -1;
			}
		}
		else
			wordTemp[i] = symbol;
	}
	CloseFile(temp);
	CloseFile(file);
	file = OpenFile(fileName, mode);
}
