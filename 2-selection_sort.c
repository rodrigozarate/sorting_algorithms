/*
* 2-selection_sort.c - Implement Selection Sort Algorithm
* Date: 21, October 2021
* Author: Oscar Angel and Rodrigo Zárate Algecira
*/

#include <stddef.h>
#include "sort.h"

/**
* selection_sort - Implements Selection sort algorithm
* @array: pointer
* @size: structure
*/

void selection_sort(int *array, size_t size)
{
	size_t i, j, j_min;
	/* walk trough all array */
	for (i = 0; i < size; i++)
	{
		j_min = i;
		/* test to determine min */
		for (j = i + 1; j < size; j++)
		{
			/* if true set new min */
			if (array[j] < array[j_min])
			{
				j_min = j;
			}
		}
		/* call swap */
		if (j_min != i)
		{
			swap(i, j_min, array, size);
		}
	}
}
/**
* swap - Swap two positions in array
* @array: pointer
* @size: structure
* @a: int key index
* @b: int key index
*/
void swap(int a, int b, int *array, size_t size)
{
	int temp_position;

	temp_position = array[a];
	array[a] = array[b];
	array[b] = temp_position;
	print_array(array, size);
}
