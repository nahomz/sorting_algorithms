#include "sort.h"

/**
 *powB - raises the number base to power power
 *@base : the base
 *@power : the power
 *Return: return the answer
 */
int powB(int base, int power)
{
	int i, prod = 1;

	for (i = 0; i < power; i++)
		prod = prod * base;
	return (prod);
}

/**
 * digitat - returns the digit of a number num at index
 * for example if num is 456 and index is 2, then 5 will be
 * returned. (123, 1) => 3 (2245, 4) => 2
 * @num: number
 * @index: the nth digit
 * Return: the digit at index inside numwhen counting from left starting from 1
 *
 */
int digitat(int num, size_t index)
{
	int zeros =  powB(10, (int)index - 1);

	if (index <= 1)
		return (num % 10);
	num -= num % zeros;
	num = num % powB(10, (int)index);
	num = num / zeros;

	return (num);
}

/**
 * create_da - creats a 2d integerarray
 * @height: the height of the double array
 * @width: the width of each array in the 2d array
 * Return: a pointer to the first array
 */
int **create_da(size_t height, size_t width)
{
	int **bucket = malloc(sizeof(int *) * height);
	size_t i = 0;

	if (!bucket)
		return (NULL);
	while (i < height)
	{
		bucket[i] = malloc(sizeof(int) * width);
		if (!bucket[i])
		{
			while (i)
				free(bucket[i]), i += 1;
			free(bucket);
			return (NULL);
		}
		i++;
	}
	return (bucket);
}

/**
 * copyfrombucket - copys data from bucket to array
 * bucket size should be of length 10 and it should be
 * a double pointer, the zeroth element of each array
 * inside the bucket should be the number of elements stored
 * insider that array +1
 * @bucket: the bucket in radix sort
 * @array: the array to copy the information to
 */
void copyfrombucket(int **bucket, int *array)
{
	const size_t NUM_DIGIT = 10;
	size_t j, index;
	int i;

	for (j = 0, index = 0; j < NUM_DIGIT; j++)
	{
		bucket[j][0]--;
		if (bucket[j][0] > 0)
		{
			i = 1;
			while (i <= bucket[j][0])
			{
				array[index] = bucket[j][i];
				index++;
				i++;
			}
		}
		bucket[j][0] = 1;
	}
}

/**
 * radix_sort - an implementation of the radix sort on an array of integers
 * @array: array to be sorted
 * @size: the size of the array
 *
 */
void radix_sort(int *array, size_t size)
{
	const size_t NUM_DIGIT = 10;
	size_t current_d = 1, i = 0, j;
	bool found_d = true;
	int digit, **bucket;

	if (size <= 1)
		return;
	bucket = create_da(NUM_DIGIT, size + 1);
	if (!bucket)
		return;
	/*set the empty space to be 1*/
	for (i = 0; i < NUM_DIGIT; i++)
		bucket[i][0] = 1;

	for (i = 1; i < current_d + 1; i++)
	{
		for (j = 0; j < size; j++)
		{
			digit = digitat(array[j], current_d);
			bucket[digit][bucket[digit][0]] = array[j];
			bucket[digit][0] += 1;
			if (digit)
				found_d = true;
		}
		/*print_db(bucket, NUM_DIGIT, size);*/
		copyfrombucket(bucket, array);
		if (!found_d)
			break;
		found_d = false;
		print_array(array, size);
		current_d++;
	}

	/*free the bucket*/
	i = 0;
	while (i < NUM_DIGIT)
		free(bucket[i]), i++;
	free(bucket);
}
