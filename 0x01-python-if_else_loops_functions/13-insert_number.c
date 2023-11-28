#include "lists.h"

/**
 * insert_node - inserts a new node
 * at a given position.
 * @head: head of a list.
 * @number: index of the list where the new node is
 * added.
 * Return: the address of new node, or NULL if it
 * fails.
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new;
	listint_t *new_head, *prev;

	new_head = *head;
	new = malloc(sizeof(listint_t));

	if (new == NULL)
		return (NULL);

	while (new_head != NULL)
	{
		if (new_head->n > number)
			break;
		prev = new_head;
		new_head = new_head->next;
	}

	new->n = number;

	if (*head == NULL)
	{
		new->next = NULL;
		*head = new;
	}
	else
	{
		new->next = new_head;
		if (new_head == *head)
			*head = new;
		else
			prev->next = new;
	}

	return (new);
}
