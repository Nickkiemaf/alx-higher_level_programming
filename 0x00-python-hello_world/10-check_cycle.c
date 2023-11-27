#include "lists.h"

/**
 * check_cycle -checks if a singly linked list has
 * a cycle
 * @list: pointer to the list
 * Return: 0 if no cycle
 * or 1 if cycle
*/
int check_cycle(listint_t *list)
{
	listint_t *node;
	listint_t *prev;

	node = list;
	prev = list;
	while (list && node && node->next)
	{
		list = list->next;
		node = node->next->next;

		if (list == node)
		{
			list = prev;
			prev = node;
			while (1)
			{
				node = prev;
				while (node->next != list && node->next != prev)
				{
					node = node->next;
				}
				if (node->next == list)
					break;

				list = list->next;
			}
			return (1);
		}
	}

	return (0);
}
