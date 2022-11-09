#include "sort.h"

/**
 * bubble_sort - A type of sorting algorithm
 * @array: The array of integers to be sorted
 * @size: The length of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t count, idx;	/* count = outer loop count; idx = inner loop position; */
	int tmp, flag;	/* tmp = used for swapping; flag = check if sorted */

	if (size < 2)	/* array does not need to be sorted if length is less than 2 */
		return;

	for (count = 0; count < size; count++)
	{
		flag = 0;	/* reset flag to compare if run through needed a sort */
		for (idx = 0; idx < size - 1; idx++)
		{
			if (array[idx] > array[idx + 1]) /* compares ints in array */
			{
				tmp = array[idx];
				array[idx] = array[idx + 1];
				array[idx + 1] = tmp;
				print_array(array, size);
				flag = 1;	/* Raises flag to say a swap has been made */
			}
		}

		if (flag == 0) /* if last run through didn't need to be sorted-> end. */
			return;
	}
}
