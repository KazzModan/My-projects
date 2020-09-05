#include <stdio.h>

int main()
{
	double number1, number2, result;
	char operation;
	printf("Enter first and second number: ");
	scanf_s("%lf %lf", &number1, &number2);
	printf("Choose operation (+,-,/,*)");
	scanf_s("%*c");
	scanf_s("%c", &operation);
	switch (operation)
	{
	case '+':
		result = number1 + number2;
		printf("result is: %lf", result);
		break;
	case '-':
		result = number1 - number2;
		printf("result is: %lf", result);
		break;
	case '*':
		result = number1 * number2;
		printf("result is: %lf", result);
		break;
	case '/':
		result = number1 / number2;
		if (number2 == 0)
		{
			printf("second number =0\n");
			break;
		}
		printf("result is: %lf", result);
		break;
	default:
		printf("Wrong operation");
		break;
	}

	return 0;
}