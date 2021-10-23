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
	size_t i, j, gap;
	int tmp;
	int second_swap;

	gap = 1;
	while (gap < size)
		gap = gap * 3 + 1;
	gap /= 3;
	while (gap != 1)
	{
		i = 0;
		j = gap;
		while (j < size)
		{
			if (array[i] > array[j])
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				second_swap = i - gap;
					if (second_swap >= 0 && array[second_swap] > array[i])
					{
						tmp = array[second_swap];
						array[second_swap] = array[i];
						array[i] = tmp;
					}
			}
			i++;
			j++;
		}
		print_array(array, size);
		gap /= 3;
	}
	insertionsort(array, size);
	print_array(array, size);
}

/**
 * insertionsort - sorts array of integers following the insertion sort alg.
 *
 * @array: Array to convert to a doubly linked list
 * @size: Size of the array
 *
 * Return: Void
 */
void insertionsort(int *array, size_t size)
{
        size_t i, j, k, l;
        int tmp;

        i = 0;
        j = 1;
        while (j < size)
        {
                k = i;
                l = j;
                while (array[k] > array[l] && k >= 0)
                {
                        tmp = array[k];
                        array[k] = array[l];
                        array[l] = tmp;
                        k--;
                        l--;
                }
                i++;
                j++;
        }
}
