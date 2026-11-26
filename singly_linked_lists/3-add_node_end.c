
#include <stdlib.h>
#include "lists.h"

/**
 * add_node_end - Adds a new node at the end of a list
 * @head: Double pointer to the head of the list
 * @str: String to duplicate
 *
 * Return: Address of the new node, or NULL if it fails
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new_node, *current;
	unsigned int len = 0, i;

	if (head == NULL || str == NULL)
		return (NULL);
	while (str[len])
		len++;
	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
		return (NULL);
	new_node->str = malloc(sizeof(char) * (len + 1));
	if (new_node->str == NULL)
		return (free(new_node), NULL);
	for (i = 0; i <= len; i++)
		new_node->str[i] = str[i];
	new_node->len = len;
	new_node->next = NULL;
	if (*head == NULL)
		*head = new_node;
	else
	{
		current = *head;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
	}
	return (new_node);
}

