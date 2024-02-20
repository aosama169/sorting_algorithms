#include "sort.h"

/**
 * selection_sort - sort list with selection sort
 * @array: array to print
 * @size: Num of elements in array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, c, mins, tmp, swap;

	if (array == NULL)
		return;
	for (i = 0; i < size; i++)
	{
		for (mins = i, c = i; c < size; c++)
			if (array[c] < array[mins])
			{
				mins = c;
				swap = 1;
			}
		if (swap == 1)
		{
			tmp = array[mins];
			array[mins] = array[i];
			array[i] = tmp;
			print_array(array, size);
			swap = 0;
		}
	}
}
