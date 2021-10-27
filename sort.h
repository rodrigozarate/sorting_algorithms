#ifndef SORT_H_BIG_O
#define SORT_H_BIG_O

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void swap_node(listint_t *node_x, listint_t *node_y, listint_t **head);
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void swap(int a, int b, int *array, size_t size);
void quick_part(int *array, int low, int high, size_t size);
size_t lomuto(int *array, int low, int high, size_t size);
void shell_sort(int *array, size_t size);
void insertionsort(int *array, size_t size);
void counting_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
int hoare_partition(int *array, int low, int high, size_t size);
void recursion(int *array, int low, int high, size_t size);
void bitonic_sort(int *array, size_t size);
void dohalf(int *array, int flag, size_t size, size_t initsize);
void merge(int *array, int flag, size_t size);

#endif /* SORT_H_BIG_O */
