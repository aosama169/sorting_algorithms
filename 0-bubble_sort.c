#include "sort.h"

/**
 * bubble_sort - sort list with bubble sort algorithm
 * @array: array to print
 * @size: Num of elements in array
 */
void bubble_sort(int *array, size_t size)
{
	size_t x = 0, sz = size;
	int holder;

	if (array == NULL)
		return;
	for (sz = size; sz > 0; sz--)
	{
		for (x = 0; x < size - 1; x++)
		{
			if (array[x] > array[x + 1])
			{
				holder = array[x];
				array[x] = array[x + 1];
				array[x + 1] = holder;
				print_array(array, size);
			}
		}
	}
}
