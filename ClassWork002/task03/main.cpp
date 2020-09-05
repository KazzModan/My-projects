#pragma warning(disable : 4996
#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE* file;
	int number;
	int count = 0;
	if (!(file = fopen("numbers.txt", "r")))
	{
		printf("Sorry,can't open file");
		return 1;
	}
	while (fscanf(file, "%d", &number) != EOF)
	{
		printf("%d \n", number);
		count++;
	}
	printf("count of this number = %d", count);
	if (fclose(file))
	{
		printf("Sorry, i can't close file\n");
		return 2;
	}

	return 0;
}