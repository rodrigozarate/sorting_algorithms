/*
* 3-quick_sort.c - Implement Quick Sort Algorithm
* Date: 21, October 2021
* Author: Oscar Angel and Rodrigo Zárate Algecira
*/

#include <stddef.h>
#include <stdio.h>
#include "sort.h"

/**
* quick_sort - Implements quick sort algorithm
* @array: pointer
* @size: size_t int special definition
*/

void quick_sort(int *array, size_t size)
{
	size_t low, high;

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
*/
void quick_part(int *array, size_t low, size_t high, size_t size)
{
	size_t partition;

	/* setup vars */
	printf("in quick_part \n");
	
	printf("low: %zu - high: %zu - init_size: %zu\n", low, high, size);
	printf("prev oop \n");
	printf("Low: %zu - High: %zu", low, high);
	if (low < high)
	{
		printf("Low: %zu - High: %zu \n", low, high);
		partition = lomuto(array, low, high, size);
		printf("Partition: %zu \n", partition);
		quick_part(array, low, partition - 1, size);
		quick_part(array, partition + 1, high, size);
	}
}

/**
* lomuto - Implements lomuto partition
* @array: pointer
* @low: size_t int special definition
* @high: size_t int special definition
* @size: size_t int special definition to be able to print array
*/
size_t lomuto(int *array, size_t low, size_t high, size_t size)
{
	size_t i, j;
	int pivot, temp;

	printf("in lomuto \n");
	printf("low: %zu - high: %zu - size: %zu\n", low, high, size);
	pivot = array[high];
	printf("Pivot: %d \n", pivot);
	i = low -1;
	j = low;
	for(; j <= high; j++)
	{
		if(pivot >= array[j])
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			print_array(array, size);
		}
	}
	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;
	printf("end of for in lomuto \n");
	print_array(array, size);
	return (i + 1);
}
