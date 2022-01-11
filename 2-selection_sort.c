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
* selection_sort - an implementation of the selection sort algorithm
* @array: the array to be sorted
* @size:size of the array
 */
void selection_sort(int *array, size_t size)
{

	unsigned int i = 0, j = 0, tmp_loc = 0;
	int tmp;

	while (i < size)
	{
		j = i;
		tmp = array[j], tmp_loc = j;
		/*look for the smallest element*/
		while (j < size)
		{
			if (array[j] < tmp)
				tmp = array[j], tmp_loc = j;
			j++;
		}
		/*swap the smallest element with the current*/
		if (array[i] != array[tmp_loc])
		{
			swap(array + i, array + tmp_loc);
			print_array(array, size);
		}
		i++;
	}
}
