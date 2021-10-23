/*
* 3-quick_sort.c - Implement Quick Sort Algorithm
* Date: 21, October 2021
* Author: Oscar Angel and Rodrigo Zárate Algecira
*/

#include <stddef.h>
#include "sort.h"

/**
* quick_sort - Implements quick sort algorithm
* @array: pointer
* @size: size_t int special definition
*/

void quick_sort(int *array, size_t size)
{
	int low, high;

	/* setup vars */
	low = 0;
	high = size - 1;
	/* Call recursive function */
	quick_part(array, low, high, size);

/* end */
}

/**
* quick_part - Implements recursion
* @array: pointer
* @low: size_t int special definition
* @high: size_t int special definition
* @size: size_t int special definition of array size
*/
void quick_part(int *array, int low, int high, size_t size)
{
	int partition;

	/* setup vars */
	if (low < high)
	{
		/* set pivot */
		partition = lomuto(array, low, high, size);
		/* go to init of array */
		quick_part(array, low, partition - 1, size);
		/* go to end of array */
		quick_part(array, partition + 1, high, size);
	}
}

/**
* lomuto - Implements lomuto partition
* @array: pointer
* @low: size_t int special definition
* @high: size_t int special definition
* @size: size_t int special definition to be able to print array
* Return: size_t
*/
size_t lomuto(int *array, int low, int high, size_t size)
{
	int i, j;
	int pivot, temp;

	pivot = array[high];
	i = low - 1;

	for (j = low; j <= high; j++)
	{
		if (pivot >= array[j])
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
	return (i);
}
