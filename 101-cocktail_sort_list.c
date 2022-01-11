#include "sort.h"
/**
 * swapnext - swaps a node with the next node in a doubly linked list
 * @current: the current node
 * @head: head of the doubly linked list
 */
void swapnext(listint_t *current, listint_t **head)
{
	listint_t *tmp = NULL;

	tmp = current->next;
	if (tmp->next)
		tmp->next->prev = current;
	if (current->prev)
		current->prev->next = tmp;
	else
		*head = tmp;
	current->next = current->next->next;
	tmp->prev = current->prev;
	tmp->next = current;
	current->prev = tmp;
}

/**
 * swapprev - swaps a node with the previous node in a doubly linked list
 * @current: the current node
 * @head: head of the doubly linked list
 */
void swapprev(listint_t *current, listint_t **head)
{
	listint_t *tmp = NULL;

	tmp = current->prev;
	if (current->next)
		current->next->prev = tmp;
	if (tmp->prev)
		tmp->prev->next = current;
	else
		*head = current;

	current->prev = current->prev->prev;
	tmp->next = current->next;
	tmp->prev = current;
	current->next = tmp;
}

/**
 * cocktail_sort_list - implmentation of the cocktail sort
 * @list: a pointer to the head of the linked list to be
 *       sorted
 */
void cocktail_sort_list(listint_t **list)
{
	bool swaped = true;
	listint_t *current = NULL;

	if (!list)
		return;

	current = *list;
	if (!current)
		return;
	while (swaped)
	{
		swaped = false;
		while (current->next)
		{
			if (current->n > current->next->n)
			{
				/*swap*/
				swapnext(current, list);
				swaped = true;
				print_list(*list);
			}
			else
				current = current->next;
		}
		if (!swaped)
			return;
		while (current->prev)
		{
			if (current->n < current->prev->n)
			{
				/*swap*/
				swapprev(current, list);
				swaped = true;
				print_list(*list);
			}
			else
				current = current->prev;
		}
	}
}
