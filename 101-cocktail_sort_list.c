#include "sort.h"

void swap_helper(listint_t *left, listint_t *right);
listint_t *pointers_helper(size_t type, size_t place, listint_t **list);
int length_helper(listint_t **list), swap = 0;

/**
 * cocktail_sort_list - A type of sorting algorithm
 * @list: The list of nodes to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *front = NULL, *end = NULL;
	listint_t *move = NULL, *current = NULL;
	size_t count = 0;

	if (!list || ((*list == NULL) || ((*list)->next == NULL)))
		return;

	front = *list;
	end = front;
	current = front;

	while (end->next)
		end = end->next;

	while (front != end)
	{
		swap = 0;
		while (current != end)
		{
			move = current->next;
			if (current->n <= move->n)
			{
				current = move;
				move = current->next;
			}
			if (move && current->n > move->n)
			{
				swap_helper(current, move);
				if (move->prev == NULL)
					*list = move;
				print_list(*list);
				swap = 1;
			}
			if (current->next == NULL)
				end = current;
		}
		end = pointers_helper(1, count, list);
		current = end;
		while (current != front)
		{
			move = current->prev;
			if (move && current->n >= move->n)
			{
				current = move;
				move = current->prev;
			}
			if (move && current->n < move->n)
			{
				swap_helper(move, current);
				if (current->prev == NULL)
					*list = current;
				print_list(*list);
				swap = 1;
			}
			if (current->prev == NULL)
				front = current;
		}
		if (swap == 0)
			return;
		front = pointers_helper(0, count, list);
		count++;
	}
}

/**
 * swap_helper - Swaps the position of two nodes
 * @left: The node to swap towards the start of the list
 * @right: The node to swap towards the end of the list
 */
void swap_helper(listint_t *left, listint_t *right)
{
	listint_t *hold_l = left->prev;
	listint_t *hold_r = right->next;

	left->next = right->next;
	right->next = left;
	right->prev = hold_l;
	if (hold_r)
		hold_r->prev = left;
	if (hold_l)
		hold_l->next = right;
	left->prev = right;
}

/**
 * pointers_helper - Determines placement of the front/end pointers
 * @type: Whether the pointer to set is the front or end
 * @place: Where in the list to set the pointer
 * @list: The list
 *
 * Return: Either the point where front would need to equal or -1
 */
listint_t *pointers_helper(size_t type, size_t place, listint_t **list)
{
	listint_t *placement = *list;
	size_t count = 0;

	if (type == 1)
	{
		count = length_helper(list) - place;
		while (count != place + 1)
		{
			placement = placement->next;
			count--;
		}
	}
	else
	{
		count = 0;
		while (count != place + 1)
		{
			placement = placement->next;
			count++;
		}
	}

	return (placement);
}

/**
 * length_helper - Determines length of list and when the shaker sort must stop
 * @list: The list
 *
 * Return: Either the point where front would need to equal or -1
 */
int length_helper(listint_t **list)
{
	listint_t *current = *list;
	int count = 0;

	while (current)
	{
		current = current->next;
		count++;
	}

	return (count);
}
