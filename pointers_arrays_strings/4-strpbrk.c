#include "main.h"

/**
 * _strpbrk - searches a string for any accepted byte
 * @s: string to search
 * @accept: characters to search for
 *
 * Return: pointer to the first matching character, or NULL
 */
char *_strpbrk(char *s, char *accept)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	while (s[i] != '\0')
	{
		j = 0;
		while (accept[j] != '\0')
		{
			if (s[i] == accept[j])
				return (s + i);
			j++;
		}
		i++;
	}
	return (0);
}
