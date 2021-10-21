/*
* 1-insertion_sort_list.c - Implement insertion sort algorithm
* Date: 20, October 2021
* Author: Oscar Angel and Rodrigo Zárate Algecira
*/

#include <stddef.h>
#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
* insertion_sort_list - function that sorts a doubly linked list of integers
* in ascending order using the Insertion sort algorithm
*
* @array: pointer
* @size: structure
*
* Return: Void
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *sorted_ptr = *list;
	listint_t *runner_ptr = NULL;
	listint_t *tmp = NULL;

	if (!*list) /* GUARD CONDITION */
		return (NULL);
	while (sorted_ptr != NULL)
	{
		tmp = sorted_ptr->next;
		if (!tmp)
		{
			if (tmp->n => sorted_ptr->n)
			{
				sorted_ptr = sorted_ptr->next;
				continue;
			}
			else
			{
				runner_ptr = sorted_ptr;
				while (runner_ptr->prev !=
			}
		}
		sorted_ptr = sorted_ptr->next;
	}
}

/**
 * create_listint - Creates a doubly linked list from an array of integers
 *
 * @array: Array to convert to a doubly linked list
 * @size: Size of the array
 *
 * Return: Pointer to the first element of the created list. NULL on failure
 */
listint_t *create_listint(const int *array, size_t size)
{
    listint_t *list;
    listint_t *node;
    int *tmp;

    list = NULL;
    while (size--)
    {
        node = malloc(sizeof(*node));
        if (!node)
            return (NULL);
        tmp = (int *)&node->n;
        *tmp = array[size];
        node->next = list;
        node->prev = NULL;
        list = node;
        if (list->next)
            list->next->prev = list;
    }
    return (list);
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    listint_t *list;
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    list = create_listint(array, n);
    if (!list)
        return (1);
    print_list(list);
    printf("\n");
    insertion_sort_list(&list);
    printf("\n");
    print_list(list);
    return (0);
}
