
#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *saved_head;
	dlistint_t *tmp;
	unsigned int p;

	if (*head == NULL)
	{
		return (-1);
	}
	saved_head = *head;
	if (index == 0)
	{
		tmp = *head;
		*head = (*head)->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(tmp);
		return (1);
	}
	for (p = 0; *head != NULL && p < index - 1; p++)
		*head = (*head)->next;

	if (*head == NULL || (*head)->next == NULL)
	{
		*head = saved_head;
		return (-1);
	}
	
	tmp = (*head)->next->next;
	free((*head)->next);
	(*head)->next = tmp;
	if (tmp != NULL)
		tmp->prev = *head;

	*head = saved_head;
	return (1);
}

