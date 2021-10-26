#include "sort.h"

int max_num(int *array, size_t size);

/**
 * counting_sort
 *
 * Return: Always 0
 */
void counting_sort(int *array, size_t size)
{
	int *count_array;
	int i, max, n;

	max = max_num(array, size);
	n = max + 1;
	count_array = malloc(sizeof(int) * n);
	if (!count_array)
		return;

	for (i = 0; i < n; i++)
	{
		count_array[i] = 0;
	}
	for (i = 0; i < (int)size; i++)
	{
		++count_array[array[i]];
	}
	for (i = 1; i < n; i++)
	{
		count_array[i] = count_array[i] +  count_array[i - 1];
	}
	for (i = 0; i < (int)size; i++)
	{
		array[i] = 0;
	}
	for (i = 0; i < n; i++)
	{
		++array[count_array[i]];
	}
	for (i = 1; i < n; i++)
	{
		array[i] = array[i] +  array[i - 1];
	}
	print_array(count_array, n);
	free(count_array);
}

/**
 * max_num - function that finds the larges number in an array.
 *
 * @array: array of integers.
 * @size: size of the array.
 *
 * Return: integer with larges num in the array.
 */
int max_num(int *array, size_t size)
{
	int i;
	int max;

	for (i = 0; i < (int)size; i++)
	{
		if (array[i] >= max)
			max = array[i];
	}
	return (max);
}
