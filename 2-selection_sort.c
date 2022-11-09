#include "sort.h"
/**
 * selection_sort - Sorts by selection
 * @array: Array to sort
 * @size: Size of array
 * Return: None
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0;
	size_t j = 0;
	size_t min = 0;
	int temp = 0;

	if (size == 1)
	{
		return;
	}
	else
		for (i = 0; i < size; i++)
		{
			min = i;
			for (j = i + 1; j < size; j++)
			{
				if (array[j] < array[min])
					min = j;
			}
			if (min != i)
			{
				temp = array[i];
				array[i] = array[min];
				array[min] = temp;
				print_array(array, size);
			}
	}
}
