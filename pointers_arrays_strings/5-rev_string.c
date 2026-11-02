#include "main.h"

/**
 * rev_string - reverses a string
 * @s: string to reverse
 */
void rev_string(char *s)
{
	int i;
	int length;
	char temp;

	length = 0;

	while (s[length] != '\0')
	{
		length++;
	}

	length--;

	for (i = 0; i < length; i++)
	{
		temp = s[i];
		s[i] = s[length];
		s[length] = temp;
		length--;
	}
}
