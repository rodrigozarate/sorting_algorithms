/*
* swap_node.c - Implement insertion sort algorithm
* Date: 20, October 2021
* Author: Oscar Angel and Rodrigo Zárate Algecira
*/

#include <stddef.h>
#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
* swap_node - swaps two connected nodes of a double linked list where
* first_node must come first in the linked list, and second_node next.
*
* @first_node: pointer to pointer to listint_t node
* @second_node: pointer to pointer to listint_t node
*
* Return: Void
*/
void swap_node(listint_t **first_node, listint_t **second_node)
{
	if (!*first_node) /* EDGE CASE: one node hits NULL */
		return;
	if (!*second_node) /* EDGE CASE: one node hits NULL */
		return;
	if (*first_node == *second_node) /* EDGE CASE: both nodes are the same */
		return;
	if ((*first_node)->prev == NULL && (*second_node)->next == NULL)
	{
		(*second_node)->next = (*second_node)->prev;
		(*first_node)->prev = (*first_node)->next;
		(*second_node)->prev = NULL;
		(*first_node)->next = NULL;
	}
	else if ((*first_node)->prev == NULL) /* EDGE: first node is head of DLL */
	{
		(*first_node)->prev	= (*first_node)->next;
		(*first_node)->next = (*second_node)->next;
		(*second_node)->next->prev = (*second_node)->prev;
		(*second_node)->next = (*second_node)->prev;
		(*second_node)->prev = NULL;
	}
	else if ((*second_node)->next == NULL) /* EDGE: second nd is tail of DLL */
	{
		(*second_node)->next = (*second_node)->prev;
		(*second_node)->prev = (*first_node)->prev;
		(*first_node)->prev->next = (*first_node)->next;
		(*first_node)->prev = (*first_node)->next;
		(*first_node)->next = NULL;
	}
	else
	{
		(*first_node)->prev->next = (*first_node)->next;
		(*second_node)->next->prev = (*second_node)->prev;
		(*second_node)->prev = (*first_node)->prev;
		(*first_node)->prev = (*first_node)->next;
		(*first_node)->next = (*second_node)->next;
		(*second_node)->next = (*second_node)->next->prev;
	}
}
