
#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * print_char - prints a character
 * @args: argument list
 */
void print_char(va_list args)
{
	printf("%c", va_arg(args, int));
}

/**
 * print_integer - prints an integer
 * @args: argument list
 */
void print_integer(va_list args)
{
	printf("%d", va_arg(args, int));
}

/**
 * print_float - prints a float
 * @args: argument list
 */
void print_float(va_list args)
{
	printf("%f", va_arg(args, double));
}

/**
 * print_string - prints a string
 * @args: argument list
 */
void print_string(va_list args)
{
	char *str;

	str = va_arg(args, char *);
	if (str == NULL)
		str = "(nil)";
	printf("%s", str);
}

/**
 * print_all - prints anything
 * @format: list of types of arguments
 */
void print_all(const char * const format, ...)
{
	va_list args;
	unsigned int i, j;
	char *separator;
	print_t types[] = {
		{'c', print_char},
		{'i', print_integer},
		{'f', print_float},
		{'s', print_string},
		{'\0', NULL}
	};

	separator = "";
	va_start(args, format);
	i = 0;

	while (format != NULL && format[i] != '\0')
	{
		j = 0;
		while (types[j].specifier != '\0')
		{
			if (format[i] == types[j].specifier)
			{
				printf("%s", separator);
				types[j].print(args);
				separator = ", ";
			}
			j++;
		}
		i++;
	}

	va_end(args);
	printf("\n");
}

