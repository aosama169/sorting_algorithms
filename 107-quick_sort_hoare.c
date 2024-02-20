#include "sort.h"

/**
 * partition_h - array partition
 * @array: array to sort
 * @fstIdx: first position
 * @lstIdx: last position
 * @size: array size
 * Return: int pivot index
 */
int partition_h(int *array, int fstIdx, int lstIdx, size_t size)
{
	int pivot = array[lstIdx], i = fstIdx - 1, j = lstIdx + 1, aux;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (j < i)
			return (j);
		if (array[i] > array[j])
		{
			aux = array[i];
			array[i] = array[j];
			array[j] = aux;
			print_array(array, size);
		}
	}
}

/**
 * qsh - sorts an array of integers recursively
 * @array: array to sort
 * @fstIdx: first position
 * @lstIdx: last position
 * @size: array size
 */
void qsh(int *array, int fstIdx, int lstIdx, size_t size)
{
	int pivot;

	if (fstIdx < lstIdx)
	{
		pivot = partition_h(array, fstIdx, lstIdx, size);
		qsh(array, fstIdx, pivot, size);
		qsh(array, pivot + 1, lstIdx, size);
	}
}

/**
 * quick_sort_hoare - sorts an array of integers using the Quick
 * sort hoare algorithm  in ascending order
 * @array: array to sort
 * @size: array size
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	qsh(array, 0, size - 1, size);
}
