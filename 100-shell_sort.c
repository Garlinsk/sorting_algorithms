#include "sort.h"

/**
 * shell_sort - Implementaiton of the shell sort algorithm
 * @array: Unsorted array
 * @size: Size of the array
 * Return: Never
 */
void shell_sort(int *array, size_t size)
{
	int temp = 0;
	size_t i = 0, j = 0;
	size_t gap = 0;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3); gap = gap * 3 + 1) /* Def gap on arr size */
		;

	while (gap > 0)
	{
		for (i = gap; i < size; i++) /* Move through remaining array after the gap */
		{
			temp = array[i];
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
			{
				array[j] = array[j - gap]; /* Swap val before gap with after the gap */
			}
			array[j] = temp;
		}
		gap = (gap - 1) / 3; /* Divide the gap by three and start again */
		print_array(array, size);
	}
}
