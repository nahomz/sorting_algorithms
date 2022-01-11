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
 * shiftDown - fix's part of a heap trea to be correct
 * @parent: the parent of the sub heap
 * @end: the last index upto which the heap will be fixed
 * @array: the array containing the subset to be fixed
 * @size: full size of the array
 */
void shiftDown(int *array, size_t parent, size_t end, size_t size)
{
	size_t lchild = parent * 2 + 1, rchild;
	size_t swap_with = parent;

	while (lchild < end)
	{

		if (array[lchild] > array[swap_with])
			swap_with = lchild;

		rchild = lchild + 1;
		if (rchild < end && array[rchild] > array[swap_with])
			swap_with = rchild;

		/*if swap_with didnt change the node is already ok*/
		if (parent == swap_with)
			return;
		/*other wise swap and fix the children*/
		else
		{
			swapnprint(array + parent, array + swap_with, array, size);
			parent = swap_with;
			lchild = parent * 2 + 1;
		}
	}


}



/**
 * buildMaxHeap - builds a max heap
 * @array: the array to be changed into a heap
 * @size: the size of the array
 */
void buildMaxHeap(int *array, size_t size)
{
	size_t parent = size - 1;
	size_t root = 0;

	while (parent + 1 > root)
	{
		shiftDown(array, parent, size, size);
		if (!parent)
			break;
		parent--;
	}

}

/**
 * heap_sort - an implementaion of the heap_sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 */
void heap_sort(int *array, size_t size)
{
	size_t end = size - 1;
	size_t root = 0;

	if (size <= 1)
		return;

	buildMaxHeap(array, size);

	while (end > root)
	{
		swapnprint(array + root, array + end, array, size);
		shiftDown(array, root, end, size);
		end--;
	}

}
