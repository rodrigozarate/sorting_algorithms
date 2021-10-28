/*
* 1000-sort_deck.c - Sort deck
* Author: Rodrigo Zárate Algecira
* Date: 27, oct, 2021
*/

#include <stdlib.h>
#include <stdio.h>
#include "deck.h"

/**
* sort_deck - Sort the cards
* @deck: double linked list
*
* Sort cards of a given struct
*/

void sort_deck(deck_node_t **deck)
{
	int flag = 1, aux1, aux2;
	size_t low = 0, high = 51, i = 0;
	deck_node_t *temp = *deck;

	while (flag)
	{
		flag = 0;
		for (; i < high; i++)
		{
			aux1 = card_id(temp);
			aux2 = card_id(temp->next);
			if (aux2 < aux1)
			{
				swap_deck(deck, temp);
				flag = 1;
			}
			else
				temp = temp->next;
		}
		if (!flag)
			break;
		flag = 0;
		for (; i > low; i--)
		{
			aux1 = card_id(temp);
			aux2 = card_id(temp->prev);
			if (aux2 > aux1)
			{
				swap_deck(deck, temp->prev);
				flag = 1;
			}
			else
				temp = temp->prev;
		}
		high--;
		low++;
	}
}

/**
* swap_deck - swap node in deck
* @deck: pointer to head
* @node: swap node
*
* swap nodes reconnecting prev and next
*/

void swap_deck(deck_node_t **deck, deck_node_t *node)
{
	node->next->prev = node->prev;
	if (node->prev)
	{
		node->prev->next = node->next;
	}
	else
	{
		*deck = node->next;
	}

	node->prev = node->next;
	node->next = node->next->next;
	node->prev->next = node;

	if (node->next)
	{
		node->next->prev = node;
	}
}

/**
* card_id - give id to each card
* @node: pointer
* Return: int
*
* Match cards value with list
*/

int card_id(deck_node_t *node)
{
	int i, myval;

	char *values[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9",
				"10", "Jack", "Queen", "King"};

	for (i = 0; i < 13; i++)
	{

		if (!strcmp(node->card->value, values[i]))
		{
			myval = (i + (13 * node->card->kind));
			return (myval);
		}
	}
	exit(EXIT_FAILURE);
}
