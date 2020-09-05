#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>

int main()
{
    const int SIZE = 30;
    FILE* file;
    char name[SIZE];
    char surname[SIZE];
    if (!(file = fopen("Text.txt", "w")))
    {
        printf("Sorry,can't open file");
        return 1;
    }
    printf("Enter your name: ");
    scanf("%s", &name);
    fprintf(file, "Name: %s\n", name);
    printf("Enter your surname: ");
    scanf("%s", &surname);
    fprintf(file, "Surname: %s\n", surname);
    if (fclose(file))
    {
        printf("Sorry,can't close file");
        return 2;
    }

    return 0;
}