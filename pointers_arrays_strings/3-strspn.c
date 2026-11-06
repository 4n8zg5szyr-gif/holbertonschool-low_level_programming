#include "main.h"

/**
 * _strspn - gets the length of a prefix substring
 * @s: string to search
 * @accept: accepted characters
 *
 * Return: number of accepted characters at the beginning of s
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	while (s[i] != '\0')
	{
		j = 0;
		while (accept[j] != '\0' && s[i] != accept[j])
			j++;

		if (accept[j] == '\0')
			return (i);

		i++;
	}
	return (i);
}
