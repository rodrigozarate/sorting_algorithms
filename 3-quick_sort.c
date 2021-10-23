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
* @size: structure
*/

void quick_sort(int *array, size_t size)
{
	size_t low, high;

	/* setup vars */
	low = 0;
	hight = size;
	/* Call recursive function */
	quick_part(array, low, high);
		
/* end */
}

void quick_part(int *array, size_t low, size_t high)
{
	size_t init_size;

	/* setup vars */
	init_size = high;
	if (array[low] < array[high])
	{
		partition = lomuto(array, low, high, init_size);
		quick_part(array, low, partition - 1);
		quick_part(array, partition + 1, high);
	}
}

size_t lomuto(int *aray, size_t low, size_t high, size_t size)
{
	size_t i, j;
	int temp;

	i = low -1;
	for(j = low; j < high; j++)
	{
		if(pivot >= array[j])
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			print_array(array, size);
		}
	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;
	}
	return (i + 1);
}
