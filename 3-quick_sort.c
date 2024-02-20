#include "sort.h"

/**
 * partition - array partitions
 * @array: array to be sorted
 * @fst: first position index
 * @last: last position index
 * @size: array size int
 * Return: int pivot indexes
 */
int partition(int *array, int fst, int last, size_t size)
{
	int i = fst - 1, aux, j;

	for (j = fst; j <= last - 1; j++)
	{
		if (array[j] < array[last])
		{
			i++;
			if (i < j)
			{
				aux = array[i];
				array[i] = array[j];
				array[j] = aux;
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] > array[last])
	{
		aux = array[i + 1];
		array[i + 1] = array[last];
		array[last] = aux;
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * qs - sorts array of int recursive
 * @array: array to be sorted
 * @fst: first position index
 * @last: last position index
 * @size: array size int
 */
void qs(int *array, int fst, int last, size_t size)
{
	int pivot;

	if (fst < last)
	{
		pivot = partition(array, fst, last, size);
		qs(array, fst, pivot - 1, size);
		qs(array, pivot + 1, last, size);
	}
}

/**
 * quick_sort - sorts array of int using  Quic sort
 * @array: array to be sorted
 * @size: array size
 */
void quick_sort(int *array, size_t size)
{
	qs(array, 0, size - 1, size);
}
