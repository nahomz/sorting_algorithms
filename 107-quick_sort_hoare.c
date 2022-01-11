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
 * with the hoare scheme in mind
 * @array: the array to be sorted
 * @size: the length of the array
 * @beg: the begning of the usnorted subset of the array from the left
 *    [1,2,4,3,7,6,8] in this case index 2
 * @end: the begning of the unsorted subset of the array from the right
 */
void quick_sort_rec(int *array, size_t size, size_t beg, size_t end)
{
	size_t l = beg, r = end;

	if (end <= beg || size <= 1 || !array)
		return;
	if (end == beg + 1)
	{
		if (array[beg] > array[end])
			swapnprint(array + beg, array + end, array, size);
		return;
	}

	while (l < r)
	{
		while (array[l] <= array[r] && l < r)
			l++;
		if (l >= r)
			break;
		swapnprint(array + l, array + r, array, size);
		while (array[r] > array[l] && r > l)
			r--;
		if (r <= l)
			break;
		swapnprint(array + r, array + l, array, size);
	}
	if (l > beg)
		if (l - 1 > beg)
			quick_sort_rec(array, size, beg, l - 1);
	if (end > l + 1)
		quick_sort_rec(array, size, l + 1, end);
}

/**
* quick_sort_hoare - an implentation of the quick sort  algorithhm
* with the Hoare scheme
* @array: the array to be sorted
* @size: the size of the array
*
*/
void quick_sort_hoare(int *array, size_t size)
{
	quick_sort_rec(array, size, 0, size - 1);
}
