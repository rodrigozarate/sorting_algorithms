/*
* 0-bubble_sort.c - Implement Bubble Sort Algorithm
* Date: 20, October 2021
* Author: Oscar Angel and Rodrigo Zárate Algecira
*/

#include <stddef.h>
#include "sort.h"

/**
* bubble_sort - Implements Bubble sort algorithm
* @array: pointer
* @size: structure
*/

void bubble_sort(int *array, size_t size)
{
	size_t i;
	int tempnumber;
	int swapflag;

	i = 0;
	tempnumber = 0;
	swapflag = 0;
	while (array && i + 1 < size)
	{
	/* if number is bigger advance pointer positions */
		if (array[i] > array[i + 1])
		{
		/* if numer is lower swap positions and advance pointer */
			tempnumber = array[i];
			array[i] = array[i + 1];
			array[i + 1] = tempnumber;
			/* print array */
			print_array(array, size);
			swapflag = 1;
		}
		i++;
	}
	/* if end is reached */
	/* if swaps were made */
	if (swapflag == 1)
	{
		/* start over again */
		bubble_sort(array, size);
	}
	/* else */
	/* end */
}
