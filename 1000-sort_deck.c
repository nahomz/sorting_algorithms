#include "deck.h"


/**
 * cmpDeckNode - compares two deck nodes
 * @c1: deck node one
 * @c2: deck node two
 * Return: 1 if c1 is biigger, 0 if are equal and -1 if c2 is bigger
 */
int cmpDeckNode(deck_node_t *c1, deck_node_t *c2)
{
	int c1Value, c2Value;

	/*compare with kind*/
	if (c1->card->kind > c2->card->kind)
		return (1);
	if (c1->card->kind < c2->card->kind)
		return (-1);

	/*if kind is simillar extract value*/
	if (!strcmp(c1->card->value, "Jack"))
		c1Value = 11;
	else if (!strcmp(c1->card->value, "Queen"))
		c1Value = 12;
	else if (!strcmp(c1->card->value, "King"))
		c1Value = 13;
	else if (!strcmp(c1->card->value, "Ace"))
		c1Value = 0;
	else
		c1Value = atoi(c1->card->value);

	if (!strcmp(c2->card->value, "Jack"))
		c2Value = 11;
	else if (!strcmp(c2->card->value, "Queen"))
		c2Value = 12;
	else if (!strcmp(c2->card->value, "King"))
		c2Value = 13;
	else if (!strcmp(c2->card->value, "Ace"))
		c2Value = 0;
	else
		c2Value = atoi(c2->card->value);

	/*compare value*/
	if (c1Value > c2Value)
		return (1);
	if (c1Value < c2Value)
		return (-1);
	return (0);
}

/**
 * swapnext - swaps a node with the next node in a doubly linked list
 * @current: the current node
 * @head: head of the doubly linked list
 */
void swapnext(deck_node_t *current, deck_node_t **head)
{
	deck_node_t *tmp = NULL;

	tmp = current->next;
	if (tmp->next)
		tmp->next->prev = current;
	if (current->prev)
		current->prev->next = tmp;
	else
		*head = current;
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
void swapprev(deck_node_t *current, deck_node_t **head)
{
	deck_node_t *tmp = NULL;

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
 * sort_deck - sorts a deck
 * @list: a pointer to the head of the dead to be
 *       sorted
 */
void sort_deck(deck_node_t **list)
{
	bool swaped = true;
	deck_node_t *current = *list;

	if (!current)
		return;
	while (swaped)
	{
		swaped = false;
		while (current->next)
		{
			if (cmpDeckNode(current, current->next) == 1)
				swapnext(current, list), swaped = true;
			else
				current = current->next;
		}
		while (current->prev)
		{
			if (cmpDeckNode(current, current->prev) == -1)
				swapprev(current, list), swaped = true;
			else
				current = current->prev;
		}
		if (!swaped)
			return;
	}
}
