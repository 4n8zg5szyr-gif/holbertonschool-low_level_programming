#include "main.h"

/**
 * times_table - Prints the 9 times table
 *
 * Return: Nothing
 */
void times_table(void)
{
	int row;
	int col;
	int result;

	for (row = 0; row < 10; row++)
	{
		for (col = 0; col < 10; col++)
		{
			result = row * col;

			if (col != 0)
			{
				_putchar(',');
				_putchar(' ');
			}
			if (result < 10 && col != 0)
			{
				_putchar(' ');
			}
			if (result >= 10)
			{
				_putchar('0' + result / 10);
			}
			_putchar('0' + result % 10);
		}
		_putchar('\n');
	}
}
