#include <stdio.h>

int main()
{
	int firstNumber, secondNumber, sum;
	printf("Enter 2 numbers:\n");
	scanf_s(" %d %d", &firstNumber, &secondNumber);
	sum = firstNumber + secondNumber;
	printf("sum is: %d \n", sum);

	return 0;
}