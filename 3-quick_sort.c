#include "sort.h"


/**
 * swapnprint - swaps two integers in an array and prints the array
 * @a: first number
 * @b: second number
 * @array: the arry to be printed
 * @size: size of the array
 */
void swapnprint(int *a, int *b, int *array, size_t size)
{
	int tmp = *a;

	*a = *b;
	*b = tmp;
	print_array(array, size);
}

/**
 * quick_sort_rec - a recursive implementation of the quick sort algorithm
 * @array: the array to be sorted
 * @size: the length of the array
 * @beg: the begning of the usnorted subset of the array from the left
 *    [1,2,4,3,7,6,8] in this case index 2
 * @end: the begning of the unsorted subset of the array from the right
 */
void quick_sort_rec(int *array, size_t size, size_t beg, size_t end)
{
	int pivot;
	size_t l = beg, r = end - 1;
	bool lfound = false, rfound = false;

	if (end <= beg || size <= 1)
		return;
	if (end == beg + 1)
	{
		if (array[beg] > array[end])
			swapnprint(array + beg, array + end, array, size);
		return;
	}
	pivot = array[end];
	while (l < end)
	{
		if (l >= r)
		{
			if (lfound)
				swapnprint(array + end, array + r, array, size), beg += 1;
			else if (rfound)
				end -= 1;
			else
				swapnprint(array + end, array + l, array, size);
			quick_sort_rec(array, size, beg, end);
			break;
		}
		if (array[l] >= pivot)
			lfound = true;
		if (array[r] < pivot)
			rfound = true;
		if (!lfound)
			l++;
		if (!rfound)
			r--;
		if (lfound && rfound)
		{
			swapnprint(array + l, array + r, array, size);
			lfound = false, rfound = false;
		}
	}
}

/**
 * quick_sort - an implementation of the quick sort algorithm
 * @array: the array to be sorted
 * @size: the length of the array
 */
void quick_sort(int *array, size_t size)
{
	quick_sort_rec(array, size, 0, size - 1);
}
