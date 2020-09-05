#pragma warning(disable : 4996
#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE* file;
	char text[50];
	bool isWord;
	int count = 0;
	if (!(file = fopen("Text.txt", "r")))
	{
		printf("Sorry,can't open file");
		return 1;
	}
	while (fscanf(file, "%s", &text) != EOF)
	{
		isWord = true;
		for (size_t i = 0; text[i] != '\0'; i++)
			if (text[i] >= 48 && text[i] <= 58)
				isWord = false;
		if (!isWord)
			continue;
		printf("%s \n", text);
		count++;
	}
	printf("count of words = %d", count);
	if (fclose(file))
	{
		printf("Sorry, i can't close file\n");
		return 2;
	}

	return 0;
}