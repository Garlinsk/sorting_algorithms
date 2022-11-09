#include "sort.h"

void swap_helper(listint_t *current, listint_t *move);

/**
 * insertion_sort_list - A type of sorting algorithm
 * @list: The list of nodes to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL, *end = NULL, *move = NULL;

	if (!list || ((*list == NULL) || ((*list)->next == NULL)))
		return;

	current = (*list)->next;
	end = *list;

	while (current)
	{
		if (current->n >= end->n)
		{
			end = current;
			current = end->next;
		}
		if (current && (current->n < end->n))
		{
			move = current->prev;
			while (move && (move->n > current->n))
			{
				swap_helper(current, move);
				move = current->prev;
				if (move == NULL)
					*list = current;
				print_list(*list);
			}
			current = end->next;
		}
	}
}

/**
 * swap_helper - Swaps the position of two nodes
 * @current: The node to swap forward
 * @move: The node to swap backward
 */
void swap_helper(listint_t *current, listint_t *move)
{
	listint_t *hold_f = move->prev;
	listint_t *hold_b = current->next;

	move->next = current->next;
	current->next = move;
	current->prev = hold_f;
	if (hold_b)
		hold_b->prev = move;
	if (hold_f)
		hold_f->next = current;
	move->prev = current;
}
