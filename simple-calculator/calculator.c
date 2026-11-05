#include <stdio.h>

/**
 * main - Entry point of the simple calculator
 *
 * Description: A and B are read as integers. Add, subtract and
 * multiply print an integer result. Divide prints a decimal result
 * (printed with %g, so 10 / 4 gives 2.5 and 10 / 2 gives 5).
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int choice;
	int c;
	int a, b;

	printf("Simple Calculator\n");

	while (1)
	{
		printf("1) Add\n");
		printf("2) Subtract\n");
		printf("3) Multiply\n");
		printf("4) Divide\n");
		printf("0) Quit\n");
		printf("Choice: ");

		if (scanf("%d", &choice) != 1)
		{
			if (feof(stdin))
				return (1);
			while ((c = getchar()) != '\n' && c != EOF)
				continue;
			printf("Invalid choice\n");
			continue;
		}

		if (choice == 0)
		{
			printf("Bye!\n");
			break;
		}

		if (choice < 0 || choice > 4)
		{
			printf("Invalid choice\n");
			continue;
		}

		printf("A: ");
		if (scanf("%d", &a) != 1)
			return (1);
		printf("B: ");
		if (scanf("%d", &b) != 1)
			return (1);

		if (choice == 1)
			printf("Result: %d\n", a + b);
		else if (choice == 2)
			printf("Result: %d\n", a - b);
		else if (choice == 3)
			printf("Result: %d\n", a * b);
		else
		{
			if (b == 0)
				printf("Error: division by zero\n");
			else
				printf("Result: %g\n", (double)a / b);
		}
	}

	return (0);
}
