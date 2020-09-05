#include <iostream>
#include <cmath>
using namespace std;
void CreateSecondPyramid(int height);
void CreateFirstPyramid(int height);
int main()
{
	int choose, height, globalChoose;
	bool isGood = false;
	while (!isGood)
	{
		cout << "Enter Height of pyromid: ";
		cin >> height;
		if (!cin || height < 1 || height> 100)
		{
			cout << "Enter again\n";
			cin.clear();
			while (cin.get() != '\n');
		}
		cout << "First pyromid or second: ";
		cin >> globalChoose;
		switch (globalChoose)
		{
		case 1:
			CreateFirstPyramid(height);
			isGood = true;
			break;
		case 2:
			CreateSecondPyramid(height);
			
			isGood = true;
			break;
		default:
			cout << "Wrong choise\n";
		}
	}
	return 0;
}
void CreateSecondPyramid(int height)
{
	{
		for (size_t i = 0; i < height; i++)
		{
			for (size_t j = 0; j < height * 2; j++)
				if (i + j >= height - 1 && abs(int(j - i)) <= height)
					cout << " #";
				else
					cout << "  ";

			cout << endl;
		}
	}
}

void CreateFirstPyramid(int height)
{
	for (size_t i = 0; i < height; i++)
	{
		for (size_t j = 0; j < height; j++)
		{
			if (i + j >= height - 1 && abs(int(j - i)) <= height)
			{
				cout << " *";
			}
			else
				cout << "  ";
		}
		cout << endl;
	}

}
