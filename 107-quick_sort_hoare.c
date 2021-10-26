/*
* 107-quick_sort_hoare.c - Implement Quick Sort - Hoare - Algorithm
* Date: 26, October 2021
* Author: Oscar Angel and Rodrigo Zárate Algecira
*/

#include <stddef.h>
#include "sort.h"

/**
* hoare_partition - Set hoare partition
* @array: pointer
* @low: first element in sort list
* @high: last element in sort list
* @size: numbers of elements in array
* Return: int
*/

int hoare_partition(int *array, int low, int high, size_t size)
{
	int temp;

	int endvalue = array[high];
	/* infinite loop */
	while (1)
	{
		/* low go up */
		while (array[low] < endvalue)
		{
			low++;
		}

		/* high go down */
		while (array[high] > endvalue)
		{
			high--;
		}

		if (low < high)
		{
			/* doo the swap */
			temp = array[low];
			array[low] = array[high];
			array[high] = temp;
			/* then print */
			print_array(array, size);
			low++;
			high--;
		}
		else
		{
			if (low != high)
			{
				return (high);
			}
			return (high - 1);
		}
	}
}

/**
* recursion - Implements Quick sort algorithm hoare flavor
* @array: pointer
* @low: first element in sort list
* @high: last element in sort list
* @size: numbers of elements in array
*/

void recursion(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		/* define pivot */
		pivot = hoare_partition(array, low, high, size);
		if (pivot > low)
		{
			/* check from low to pivot */
			recursion(array, low, pivot, size);
		}
		/* check from pivot to end */
		recursion(array, pivot + 1, high, size);
	}
}

/**
* quick_sort_hoare - Implements Quick sort algorithm hoare flavor
* @array: pointer
* @size: structure
*/

void quick_sort_hoare(int *array, size_t size)
{
	/* pass array to compare */
	/* pass size to print */
	recursion(array, 0, size - 1, size);
}
