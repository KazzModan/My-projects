#include <stdio.h>
int main()
{
	const int SIZE = 30;
	FILE* file;
	char line[SIZE];
	if (!(file = fopen("Text.txt", "r")))
	{
		printf("Sorry,i can't open file\n");
		return 1;
	}
	while (fgets(line, SIZE, file))
		printf("%s", line);
	if (fclose(file))
	{
		printf("Sorry, i can't close file\n");
		return 2;
	}

	return 0;
}