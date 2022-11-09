#include "sort.h"
int partition(int *array, int start, int end, int size);
void quicksort(int *array, int start, int end, int size);
void swap(int *array, int *a, int *b, int size);

/**
 * quick_sort - Implementation of quick sort
 * @array: Array to sort
 * @size: Size of array
 * Return: Never
 */
void quick_sort(int *array, size_t size)
{
	quicksort(array, 0, size - 1, size);
}

/**
 * quicksort - recursive function for quicksort
 * @array: Array to start
 * @start: Start of the array segment
 * @end: End of the array segment
 * @size: Size of the whole array
 * Return: None
 */
void quicksort(int *array, int start, int end, int size)
{

	int j = 0;

	if (start < end)
	{
		j = partition(array, start, end, size);
		quicksort(array, start, j - 1, size);
		quicksort(array, j + 1, end, size);

	}
}

/**
 * swap - recursive function for quicksort
 * @array: Array to start
 * @a: Index to swap
 * @b: Index to swap
 * @size: Size of the whole array
 * Return: None
 */
void swap(int *array, int *a, int *b, int size)
{
	int temp = 0;

	temp = *a;
	*a = *b;
	*b = temp;
	if (*a != *b)
		print_array(array, size);
}

/**
 * partition - recursive function for quicksort
 * @array: Array to start
 * @start: Start of the array segment
 * @end: End of the array segment
 * @size: Size of the whole array
 * Return: None
 */
int partition(int *array, int start, int end, int size)
{
	int pivot = array[end], i;
	size_t subIndex = start;

	for (i = start; i < end; i++)
	{
		if (array[i] <= pivot)
		{
			swap(array, &array[i], &array[subIndex], size);
			subIndex++;
		}

	}
	swap(array, &array[subIndex], &array[end], size);
	return (subIndex);
}
