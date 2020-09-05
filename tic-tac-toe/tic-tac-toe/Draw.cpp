#include <iostream>
#include "Header.h"

using namespace std;

int main()
{
	ShowMenu();

	return 0;
}
void ShowMenu()
{
	int choose;
	int size = 3;
	char** arrOfCross = CreateArray(size, size);
	char** arrOfZero = CreateArray(size, size);

	cout << "\t\t\tHello Brother,it's tic-tac-toe\n";
	cout << "\t\t\tChoose game mode:\n";
	cout << "\t\t\t\t1: PvP\n";
	cout << "\t\t\t\t2: PvE\n";
	cout << "\t\t\t\t";
	cin >> choose;
	switch (choose)
	{
	case 1:
		Draw(arrOfCross, arrOfZero);
	default:
		break;
	}

	cout << "\t\t\tChoose difficulty level\n";
}
void Draw(char** arrOfCross, char** arrOfZero)
{
	size_t size = 3;
	const int SIZE_OF_FIELD = 11;
	char field[SIZE_OF_FIELD][SIZE_OF_FIELD] = { ' ' };
	int x, y;
	
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			if (i == j || i + j == size - 1)
				arrOfCross[i][j] = '*';
			else
				arrOfCross[i][j] = ' ';
		}
	}
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			if (j == 1 && i == 0 || i == 1 && j == 0 || i == 2 && j == 1 || i == 1 && j == 2)
				arrOfZero[i][j] = '*';
			else
				arrOfZero[i][j] = ' ';
		}
	}
	while (true)
	{
	cout << "enter x and y ->";
	cin >> x >> y;
	bool isFirstPlayer = true;
	
		for (size_t i = 0; i < SIZE_OF_FIELD; i++)
		{
			for (size_t j = 0, newJ = 0; j < SIZE_OF_FIELD; j++, newJ++)
			{/*

				if ((i >= 0 && i < 3) && (j >= 0 && j < 3))
					cout << " " << arrOfCross[i][j];
				else if (j == 3)
					cout << " #";
				else if ((i >= 0 && i < 3) && (j > 3 && j < 7))
					cout << " " << arrOfZero[i][j - 4];
				else if (j == 7 )
					cout << " #";
				else if ((i >= 0 && i < 3) && (j > 7 && j < 11))
					cout << " " << arrOfZero[i][j - 8];
				else if (i == 3)
					cout << " #";
				else if ((i >= 3 && i < 7) && (j >= 0 && j < 3))
					cout << " " << arrOfZero[i - 4][j];
				else if ((i >= 3 && i < 7) && (j >= 3 && j < 7))
					cout << " " << arrOfCross[i - 4][j - 4];
				else if ((i >= 3 && i < 7) && (j >= 7 && j < 11))
					cout << " " << arrOfZero[i - 4][j - 8];
				else if (i == 7)
					cout << " #";
				else if ((i > 7 && i < 11) && (j >= 0 && j < 3))
					cout << " " << arrOfCross[i - 8][j];
				else if ((i > 7 && i < 11) && (j >= 4 && j < 7))
					cout << " " << arrOfZero[i - 8][j - 4];
				else if ((i > 7 && i < 11) && (j >= 8 && j < 11))
					cout << " " << arrOfCross[i - 8][j - 8];*/

				if (x == 1 && y == 1 && isFirstPlayer)
				{
					if ((i >= 0 && i < 3) && (j >= 0 && j < 3))
						cout << " " << arrOfCross[i][j];

					if (j == 3 && i < 3 || i == 3)
						cout << " #";
					else if (j == 7 && i < 3)
						cout << "       #";
					if (j == 3 && i > 3 || i == 7 || j == 7 && i > 3)
						cout << " #";
					else if (i > 3)
						cout << "  ";
					isFirstPlayer == false;
				}
				if (x == 1 && y == 1 && isFirstPlayer==false)
				{
					if ((i >= 0 && i < 3) && (j >= 0 && j < 3))
						cout << " " << arrOfZero[i][j];

					if (j == 3 && i < 3 || i == 3)
						cout << " #";
					else if (j == 7 && i < 3)
						cout << "       #";
					if (j == 3 && i > 3 || i == 7 || j == 7 && i > 3)
						cout << " #";
					else if (i > 3)
						cout << "  ";
					isFirstPlayer == !isFirstPlayer;

				}
			}
			cout << endl;

		}
	}
}
char** CreateArray(size_t rows, size_t cols)
{
	char** ptr = new char* [rows];

	for (size_t i = 0; i < rows; i++)
	{
		ptr[i] = new char[cols];
	}
	return ptr;
}
void DeleteArray(char** arr, size_t rows)
{
	for (size_t i = 0; i < rows; i++)
		delete[] arr[i];
	delete[] arr;
}
