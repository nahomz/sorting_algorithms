#include "sort.h"


/**
* selectoin_sort - an implementation of the selection sort algorithm
* @array: the array to be sorted
* @size:size of the array
 */
void selection_sort(int *array, size_t size)
{

	unsigned int i = 0, j = 0;
	int tmp;


	while (i < size)
	{
		j = i + 1;
		while (array[i] < array[j] && j < size)
			j++;
		if (j == size)
			i++;
		else
		{
			tmp = array[j];
			array[j] = array[i];
			array[i] = tmp;
			print_array(array, size);
		}
	}
}
/**
 * insertion_sort - an implementation of the insertion sort with arrays
 * @array: the array to be sorted
 * @size: the size of the array
 */
void insertion_sort(int *array, size_t size)
{

	size_t i = 0;
	size_t j;
	while (i < size)
	{
		j = i;
		while (j > 0)
		{
			if(array[j] > array[j - 1])
				break;
			swap(array + j, array + j - 1);
			j--;
		}
		i++;
	}
}
