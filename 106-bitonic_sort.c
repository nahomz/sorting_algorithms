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
 * mergeup - creats an increasing bitonic sequence by merging
 * two parts of the array
 * @array: the array to be merged it must be a bitonic sequence
 * @size: the size of the subset array
 * @fullsize: the full size of the whole array
 */
void mergeup(int *array, size_t size, size_t fullsize)
{
	int diff = size / 2;
	int i, j;

	printf("Result [%i/%i] (UP):\n", (int)size, (int)fullsize);

	for (i = diff; i > 0; i--)
		for (j = 0; j + i < (int)size; j++)
			if (array[j] > array[j + i])
				swap(array + j, array + j + i);
	print_array(array, size);
}
/**
 * mergedown - creats a decreasing bitonic sequence by merging
 * two parts of the array
 * @array: the array to be merged it must be a bitonic sequence
 * @size: the size of the subset array
 * @fullsize: the full size of the whole array
 */
void mergedown(int *array, size_t size, size_t fullsize)
{
	int diff = size / 2;
	int i, j;

	printf("Result [%i/%i] (DOWN):\n", (int)size, (int)fullsize);
	for (i = diff; i > 0; i--)
		for (j = 0; j + i < (int)size; j++)
			if (array[j] < array[j + i])
				swap(array + j, array + j + i);

	print_array(array, size);
}

/**
 * bitonicSort - a recurive helper function for the bitonic sort algorithm
 * @array: the array to be sorted
 * @size: the size of the aray/ sub array in the case of recusive calls
 * @fullsize: the full size of the array before subarrays were taken out
 */
void bitonicSort(int *array, size_t size, size_t fullsize)
{
	size_t mid = size / 2;

	if (size > 1)
	{
		printf("Merging [%i/%i] (UP):\n", (int)size, (int)fullsize);
		print_array(array, size);
		bitonicSort(array, mid, fullsize);
		mergeup(array, size, fullsize);

		/*if there is nothing left to be merged*/
		if (size + size > fullsize)
			return;
		printf("Merging [%i/%i] (DOWN):\n", (int)size, (int)fullsize);
		print_array(array + size, size);
		bitonicSort(array + size, mid, fullsize);
		mergedown(array + size, size, fullsize);
	}

}

/**
 * bitonic_sort - an implementation of the bitonic sort algorithm
 * @array: the array to be sorted
 * @size: the size of the aray
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	bitonicSort(array, size, size);
}
