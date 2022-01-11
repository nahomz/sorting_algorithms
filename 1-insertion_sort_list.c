#include "sort.h"


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
 * insertion_sort_list - implemetnation of insertion sort in
 * a doubly linked list
 * @list: a pointer to the head of the list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL, *prev_tmp = NULL, *prev = NULL;

	if (!list)
		return;
	current = *list;
	while (current)
	{
		prev = current->prev;
		/*move the current element some steps back until in position*/
		while (prev)
		{
			if (current->n >= prev->n)
				break;
			/*swap the two nodes if they are out of order*/
			swapprev(current, list);

			/*once the swap is done swap the names*/
			prev_tmp = prev;
			prev = current;
			current = prev_tmp;
			print_list(*list);
			/*
			 * go back one step so that the newly swaped(went to left) value
			 * will be your current and make sure it isn't smaller than
			 * the value in its left
			 */
			prev = prev->prev;
			current = current->prev;
		}
		current = current->next;
	}
}
