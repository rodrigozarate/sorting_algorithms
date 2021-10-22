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
* @list: pointer to pointer to listin_t node
*
* Return: Void
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *sorted_ptr;
	listint_t *second_node;

	sorted_ptr = *list;
	if (!*list) /* GUARD CONDITION */
		return;
	while (sorted_ptr != NULL)
	{
		second_node = sorted_ptr->next;
		if (!second_node)
			return;
		if (second_node->n >= sorted_ptr->n)
		{
			sorted_ptr = sorted_ptr->next;
			continue;
		}
		else
		{
			swap_node(&sorted_ptr, &second_node);
			if ((*list)->prev != NULL)
				*list = (*list)->prev;
			print_list(*list);
			sorted_ptr = *list;
			continue;
		}
		sorted_ptr = sorted_ptr->next;
	}
}
