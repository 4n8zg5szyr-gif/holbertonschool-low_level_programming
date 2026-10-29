#include "main.h"

/**
 * print_diagonal - draws a diagonal line
 * @n: number of times the character is printed
 *
 * Return: Nothing
 */
void print_diagonal(int n)
{
	int i;
	int spaces;

	for (i = 0; i < n; i++)
	{
		for (spaces = 0; spaces < i; spaces++)
			_putchar(' ');
		_putchar('\\');
	}
	_putchar('\n');
}
