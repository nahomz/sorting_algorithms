#include "sort.h"

/**
* print_elements - prints elements in an array in a given format
* @array: the array to be printed
* @size: the size of the array
*/
void print_elements(int *array, size_t size)
{
	size_t i = 0;

	while (i < size - 1)
		printf("%i, ", array[i]), i += 1;
	printf("%i\n", array[i]);
}

/**
* merge_sort_rec - a recursive merging algorithm
* in this implmentation one workgin array is utilized
* and most of the calculation (the dividing) is done
* on the actuall array
* @array: the array to be sorted
* @working_array: an array of equal size to array for
* temp work.
* @size: size of the arrays
* Return: the size of the array sorted
*/
size_t merge_sort_rec(int *array, int *working_array, size_t size)
{
	size_t left, right;
	size_t i = 0, j = 0, k = 0;
	size_t half = (size_t)(size / 2);

	if (size <= 1)
		return (size);

	/*sort each half*/
	left = merge_sort_rec(array, working_array, half);
	right = merge_sort_rec(array + half, working_array + half, size - half);

	/*merge each half*/
	printf("Merging...\n");
	printf("[left]: ");
	print_elements(array, left);
	printf("[right]: ");
	print_elements(array + left, right);

	for (k = i, j = left; i < left && j < left + right; k++)
	{
		if (array[i] > array[j])
			working_array[k] = array[j], j += 1;
		else
			working_array[k] = array[i], i += 1;
	}
	for ( ; i < left; i++, k++)
		working_array[k] = array[i];

	for ( ; j < left + right; j++, k++)
		working_array[k] = array[j];

	/*copy the changes back to the main array*/
	for (k = 0; k < right + left; k++)
		array[k] = working_array[k];
	printf("[Done]: ");
	print_elements(array, right + left);
	return (left + right);
}

/**
* merge_sort - an implementation of the merge sort algorithm
* @array: the array to be sorted
* @size: the size of the array
*/
void merge_sort(int *array, size_t size)
{
	int *work_ar = malloc(sizeof(int) * size);

	if (!work_ar)
		return;

	merge_sort_rec(array, work_ar, size);
	free(work_ar);
}
