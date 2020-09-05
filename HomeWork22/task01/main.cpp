#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	const int SIZE = 30;
	char word[SIZE];
	bool IsWordFound = false;
	cout << "enter word, which you find: ";
	cin >> word;
	for (int i = 1; i < argc; i++)
	{
		if (!strcmp(word, argv[i]))
			IsWordFound = true;
	}
	if (IsWordFound)
		cout << "word was found\n";
	else
		cout << "word wasn't found\n";
	return 0;
}