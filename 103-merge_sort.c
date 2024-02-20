#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * print_left_right - print left and right partition
 * @array: array to be sorted
 * @sz: size of 2 second array
 * @first: init position index
 * @mid: middle position index
 */
void print_left_right(int *array, int sz, int first, int mid)
{
	int k;

	printf("Merging...\n");
	printf("[left]: ");
	k = first;
	while (k < mid)
	{
		if (k != mid - 1)
			printf("%d, ", array[k]);
		else
			printf("%d\n", array[k]);
		k++;
	}

	printf("[right]: ");
	k = mid;
	while (k < sz)
	{
		if (k < sz - 1)
			printf("%d, ", array[k]);
		else
			printf("%d\n", array[k]);
		k++;
	}
}

/**
 * merge - merge values in position of array
 * @array: first array
 * @sz: size of second array
 * @cpy: copy of array
 * @first: initial position
 * @mid: middle position
 * first one of second array
 */
void merge(int *array, int sz, int first, int mid, int *cpy)
{
	int i, j, k;

	print_left_right(array, sz, first, mid);

	i = first;
	j = mid;

	printf("[Done]: ");
	k = first;
	while (k < sz)
	{
		if (i < mid && (j >= sz || array[i] <= array[j]))
		{
			cpy[k] = array[i];
			i++;
		}
		else
		{
			cpy[k] = array[j];
			j++;
		}
		if (k < sz - 1)
			printf("%d, ", cpy[k]);
		else
			printf("%d\n", cpy[k]);
		k++;
	}
}
/**
 * mergeSort - array separator
 * @cpy: copy of array
 * @first: initial position
 * @size: size of original  array
 * @array: original array
 */
void mergeSort(int *cpy, int first, int size, int *array)
{
	int mid;

	if (size - first < 2)
		return;

	mid = (size + first) / 2;

	mergeSort(array, first, mid, cpy);
	mergeSort(array, mid, size, cpy);

	merge(cpy, size, first, mid, array);
}
/**
 * copy_array - copy array of int
 * @arr: array src
 * @cpy: array dest
 * @sz : array size
 */
void copy_array(int *arr, int *cpy, int sz)
{
	int i;

	for (i = 0; i < (int)sz; i++)
		cpy[i] = arr[i];
}

/**
 * merge_sort - create partition and copy
 * @array: array
 * @sz : array size
 */
void merge_sort(int *array, size_t sz)
{
	int *cpy;

	cpy = malloc(sizeof(int) * sz - 1);

	if (cpy == NULL)
		return;

	copy_array(array, cpy, sz);

	mergeSort(cpy, 0, sz, array);
	free(cpy);
}
