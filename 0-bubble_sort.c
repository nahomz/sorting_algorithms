#include "sort.h"


/**
 * swap - swaps two integers in an array
 * @a: first number
 * @b: second number
 */
void swap(int *a, int *b)
{
	int tmp = *a;

	*a = *b;
	*b = tmp;
}

/**
 * bubble_sort -  an implementation of bubble sort
 * @array: the array to be sorted
 * @size: the size of the array
 *
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int i = 0, j = 0;
	unsigned int swapped = 0;

	if (!array || size < 2)
		return;

	while (j < size)
	{
		i = 0;
		while (i < size - 1)
		{
			if (array[i] > array[i + 1])
			{
				swap(array + i, array + i + 1);
				swapped = 1;
				print_array(array, size);
			}
			else
				i++;
		}
		/*incase it was already sorted*/
		if (!swapped)
			return;
		j++;
	}
}
