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

void print_elements(int *array, size_t size)
{
	size_t i = 0;

	while (i < size - 1)
	{
		printf("%i, ", array[i]);
		i++;
	}
	printf("%i\n", array[i]);
}

size_t merge_sort_rec(int *array, size_t size)
{

	size_t left, right;
	size_t i = 0, j = 0, k = 0;
	size_t half = (size_t)(size / 2);

	if (size <= 1)
		return size;

	/*sort each half*/
	left = merge_sort_rec(array, half);
	right = merge_sort_rec(array + half, size - half);


	printf("Merging...\n");
	printf("[left]: ");
	print_elements(array, left);
	printf("[right]: ");
	print_elements(array + left, right);
	j = left;
	while (i < left)
	{
		if (array[i] < array[j])
			i++;
		else
		{
			swap(array + i, array + j);
			/* Here insertion sort is used when merging which is no way effiencet
			 * speed wise but very effieceint space wise,  but space could be
			 * threaded for speed heare by creating new array putting each sorted
			 * element in an array and copying it back. also merge sort could also be used
			 * here which is better than the insertion sort but not much better
			 */
			/*	merge_sort_rec(array + j, right);*/
			k = j;
			while (array[k] > array[k + 1] && k + 1 < j + right)
				swap(array + k, array + k + 1), k += 1;
		}
	}
	printf("[Done]: ");
	print_elements(array, right + left);
	return (left + right);
}


void merge_sort(int *array, size_t size)
{
	merge_sort_rec(array, size);
}
