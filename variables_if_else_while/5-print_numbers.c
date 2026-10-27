#include <stdio.h>

/**
 * main - prints single digit numbers
 *
 * Return: Always 0
 */
int main(void)
{
	int number;

	for (number = 0; number <= 9; number++)
	{
		printf("%d", number);
	}
	printf("\n");

	return (0);
}
