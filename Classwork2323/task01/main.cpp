#include <iostream>
#include <ctime>
using namespace std;
void CreateArray(int** array, size_t rows, size_t cols);
void ShowArray(int** array, size_t rows, size_t cols);
void FillArray(int** array, size_t rows, size_t cols);
int main()
{
	int rows, cols;
	cout << "Enter rows and cols of array: ";
	cin >> rows >> cols;
	int** array = new int* [rows];
	srand(time(nullptr));
	CreateArray(array, rows, cols);
	FillArray(array, rows, cols);
	ShowArray(array, rows, cols);
	return 0;
}

void CreateArray(int** array, size_t rows, size_t cols)
{
	for (size_t i = 0; i < rows; i++)
	{
		array[i] = new int[cols];
	}
}

void ShowArray(int** array, size_t rows, size_t cols)
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			cout << array[i][j] << " ";
		}
		cout << endl;
	}
}

void FillArray(int** array, size_t rows, size_t cols)
{
	int counter = 10;
	
		for (size_t i = 0; i < rows; i++)
		{
			for (size_t j = 0; j < cols; j++)
			{
				if (i == 0)
					array[i][j] = counter++;
			}
		}
		for (size_t i = 0; i < rows; i++)
		{
			for (size_t j = 0; j < cols; j++)
			{
				if (j == cols - 1)
					array[i][j] = counter++;
			}
		}
		for (size_t i = 0; i < rows; i++)
		{
			for (size_t j = cols; j > 0; j--)
			{
				if (i == rows - 1)
					array[i][j - 1] = (counter++) - 1;
			}
		}
		for (size_t i = rows; i > 1; i--)
		{
			for (size_t j = 0; j < cols; j++)
			{
				if (j == 0)
					array[i - 1][j] = (counter++) - 1;
			}
		}
		FillArray(array, rows-1, cols-1);
}
