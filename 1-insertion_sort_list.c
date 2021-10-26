/*
* 1-insertion_sort_list.c - Implement insertion sort algorithm
* Date: 20, October 2021
* Author: Oscar Angel and Rodrigo Zárate Algecira
*/

#include "sort.h"

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
	listint_t *head, *prev;
	int stored;

	/* point 5 checker validation */
	if (list == NULL || (*list)->next == NULL || (*list) == NULL)
	{
		return;
	}

	head = *list;
	/* walk the list */
	while (head)
	{
		/* save initial place */
		prev = head->prev;
		stored = head->n;

		while (prev && prev->n > stored)
		{
			swap_node(prev, head, list);
			print_list(*list);
			prev = head->prev;
		}
		/* move pointer */
		head = head->next;
	}

}

/**
* swap_node - swaps two connected nodes of a double linked list where
* first_node must come first in the linked list, and second_node next.
*
* @node_x: pointer
* @node_y: pointer
* @head: double pointer
* Return: Void
*/

void swap_node(listint_t *node_x, listint_t *node_y, listint_t **head)
{
	listint_t *temp1 = NULL, *temp2 = NULL;

	/* end reached */
	if (node_x == NULL || node_y == NULL)
	{
		return;
	}

	/* temporal copy of node */
	temp1 = node_x->prev;
	temp2 = node_y->next;

	/* not pointed to NULL */
	if (temp1)
	{
		temp1->next = node_y;
	}

	if (temp2)
	{
		temp2->prev = node_x;
	}
	/* do the swap by untyign and reconect */
	node_x->next = temp2;
	node_x->prev = node_y;
	node_y->next = node_x;
	node_y->prev = temp1;

	if (temp1 == NULL)
	{
		*head = node_y;
	}
}
