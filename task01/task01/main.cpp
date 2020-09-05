#include <iostream>

using namespace std;

int main()
{	
	int choose;
	do
	{
		cout << "hey\n";
		cin >> choose;
		switch (choose)
		{
		case 1:
			do
			{
				cout << 1;
				cout << 2;
				cin >> choose;
			} while (choose != 3);
		default:
			break;
		}
	} while (choose != 0);
	return 0;
}
