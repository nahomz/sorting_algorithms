#include "sort.h"

/**
 * maxof - returns the maximum element in the array
 * @array: the array
 * @size: the size of the array
 * Return: the maximum integer
 */
int maxof(int *array, size_t size)
{
	int i;
	int max;

	if (size < 1)
		return (size);
	max = array[0];

	for (i = 0; (int)i < (int)size; i++)
		if (max < array[i])
			max = array[i];
	return (max);
}
/**
 * counting_sort - an implementation of the counting sort
 * @array: the arrray to be sorted
 * @size: the size of the array
 */
void counting_sort(int *array, size_t size)
{

	size_t i = 0, sum = 0;
	size_t max = (size_t)maxof(array, size);
	int *count;

	if (!array || size <= 1)
		return;
	count = malloc(sizeof(int) * (max + 1 + size));
	if (!count)
		return;

	for (i = 0; (int)i < (int)max + 1; i++)
		count[i] = 0;
	for (i = 0; (int)i < (int)size; i++)
		count[array[i] - 1] += 1;
	for (i = 0; (int)i < (int)max + 1; i++)
		sum += count[i], count[i] = sum;
	for (i = 0; (int)i < (int)size; i++)
		count[max + count[array[i] - 1]] = array[i], count[array[i] - 1] -= 1;

	/*copy the element back to array*/
	for (i = 0; (int)i < (int)size; i++)
		array[i] = count[max + 1 + i];
	print_array(count, max + 1);
	free(count);
}
