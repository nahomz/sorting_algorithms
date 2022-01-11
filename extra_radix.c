#include "sort.h"


/**
 * free_da - frees a 2d array with height and width given
 * @height: the length of the 2d array to be freed
 * @array: the double pointer to be freed
 */
void free_da(int **array, size_t height)
{
	size_t i = 0;

	while (i < height)
		free(array[i]), i++;
	free(array);
}


/**
 * print_db - prints a 2d array
 * @db: a pointer to the first array
 * @height: the heiht of the 2d array
 * @width: the width of each aray
 */
void print_db(int **db, size_t height, size_t width)
{
	size_t i = 0, j = 0;

	printf("[ \n");
	while (i < height)
	{
		printf(" [ ");
		j = 0;
		while (j < width)
		{
			printf("%i, ", db[i][j]);
			j++;
		}
		printf(" ]\n");
		i++;
	}
	printf("]\n");
}
