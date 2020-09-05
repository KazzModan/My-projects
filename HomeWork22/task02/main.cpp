#include <stdio.h>

int main()
{
	const int SIZE = 100;
	char line[SIZE] = "";
	char ch = ' ';
	printf("enter text: ");
	while (scanf_s("%s", line, sizeof(line)))
	{
		scanf_s("%c", &ch);
		printf("%s ", line);
		if (ch == '\n')
			break;
	}

	return 0;
}