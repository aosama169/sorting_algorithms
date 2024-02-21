#include "sort.h"

/**
 * swap - swaps 2 int position
 * @a: address of first position
 * @b: address of second position
 *
 * Return: void
 */
void swap(int *a, int *b)
{
	if (*a != *b)
	{
		*a = *a + *b;
		*b = *a - *b;
		*a = *a - *b;
	}
}

/**
 * bitonic_compare - compares bitonic
 * @up: true if UP sorting
 * @array: the array pointer
 * @start: the start position
 * @end: the stop position
 */
void bitonic_compare(int up, int *array, size_t start, size_t end)
{
	size_t half = (end - start + 1) / 2, i;

	for (i = start; i < start + half; i++)
		if ((array[i] > array[i + half]) == up)
			swap(&array[i], &array[i + half]);
}

/**
 * bitonic_merge - merges bitonic
 * @up: true if sorting
 * @array: the array pointer
 * @start: the start position
 * @end: the stop position
 */
void bitonic_merge(int up, int *array, size_t start, size_t end)
{
	size_t medi = (start + end) / 2;

	if (end - start < 1)
		return;
	bitonic_compare(up, array, start, end);
	bitonic_merge(up, array, start, medi);
	bitonic_merge(up, array, medi + 1, end);
}

/**
 * _bitonic_sort - sorts bitonic using recursion
 * @up: true if UP sorting
 * @array: array pointer
 * @size: length of array
 * @start: start position
 * @end: stop position
 */
void _bitonic_sort(int up, int *array, size_t size, size_t start, size_t end)
{
	size_t medi = (start + end) / 2;

	if (end - start < 1)
		return;
	printf("Merging [%lu/%lu] (%s):\n", end - start + 1, size,
		up ? "UP" : "DOWN");
	print_array(array + start, end - start + 1);
	_bitonic_sort(1, array, size, start, medi);
	_bitonic_sort(0, array, size, medi + 1, end);
	bitonic_merge(up, array, start, end);
	printf("Result [%lu/%lu] (%s):\n", end - start + 1, size,
		up ? "UP" : "DOWN");
	print_array(array + start, end - start + 1);
}

/**
 * bitonic_sort - sorts bitonic
 * @array: array pointer position
 * @size: length of  array
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	_bitonic_sort(1, array, size, 0, size - 1);
}
