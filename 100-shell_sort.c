#include "sort.h"

/**
 * shell_sort - Shell sorting
 * @array: array to be sorted
 * @size: size of array int
 */
void shell_sort(int *array, size_t size)
{
	int gap = 1, i, j, flag;

	while (gap < ((int)(size)))
		gap = (3 * gap) + 1;
	for (gap = (gap - 1) / 3; gap > 0; gap = (gap - 1) / 3)
	{
		for (i = gap; i < (int)size; i += 1)
		{
			flag = array[i];

			for (j = i; j >= gap && array[j - gap] > flag; j -= gap)
				array[j] = array[j - gap];

			array[j] = flag;
		}
		print_array(array, size);
	}
}
