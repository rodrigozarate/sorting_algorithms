#include <stddef.h>
#include "sort.h"

/**
 * shell_sort -  function that sorts an array of integers
 * in ascending order using the Shell sort algorithm, using the Knuth sequence.
 * @array: array of integers
 * @size: size of array
 *
 * Return: Void
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j, k, gap;
	int temp;

	/* create array of gaps lower than array size */
	for (i = 1, gap = 1; gap < size; i += 1)
	{
		gap = gap * 3 + 1;
	}
	/* remove bigger */
	gap = (gap - 1) / 3;

	while (gap > 0)
	{
		for (j = gap; j < size; j++)
		{
			temp = array[j];
			for (k = j; k >= gap && array[k - gap] > temp; k -= gap)
			{
				array[k] = array[k - gap];
			}
			array[k] = temp;
		}
		gap = (gap - 1) / 3;
		print_array(array, size);
	}

}
