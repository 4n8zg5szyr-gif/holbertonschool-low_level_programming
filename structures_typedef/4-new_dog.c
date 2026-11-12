
#include <stdlib.h>
#include "dog.h"

/**
 * new_dog - creates a new dog
 * @name: dog's name
 * @age: dog's age
 * @owner: dog's owner
 *
 * Return: pointer to the new dog, or NULL if it fails
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *dog;
	unsigned int i;
	unsigned int name_len = 0;
	unsigned int owner_len = 0;
	char *new_name;
	char *new_owner;

	if (name == NULL || owner == NULL)
		return (NULL);

	while (name[name_len] != '\0')
		name_len++;

	while (owner[owner_len] != '\0')
		owner_len++;

	dog = malloc(sizeof(dog_t));
	if (dog == NULL)
		return (NULL);

	new_name = malloc(sizeof(char) * (name_len + 1));
	if (new_name == NULL)
	{
		free(dog);
		return (NULL);
	}

	new_owner = malloc(sizeof(char) * (owner_len + 1));
	if (new_owner == NULL)
	{
		free(new_name);
		free(dog);
		return (NULL);
	}

	for (i = 0; i <= name_len; i++)
		new_name[i] = name[i];

	for (i = 0; i <= owner_len; i++)
		new_owner[i] = owner[i];

	dog->name = new_name;
	dog->age = age;
	dog->owner = new_owner;

	return (dog);
}

