#include <stdio.h>
#include <string.h>
int main()
{
	FILE* file;

	if (!(file = fopen("Text.txt", "w")))
	{
		printf("Sorry,i can't create and open file\n");
		return 1;
	}
	/*const int SIZE = 30;
	char name[30] = "", surname[30] = "";
	printf("Enter your name\n");
	scanf("%s", &name);
	fprintf(file, "Name: %s\n", name);
	printf("Enter your name\n");
	scanf("%s", &surname);*/

	return 0;
}