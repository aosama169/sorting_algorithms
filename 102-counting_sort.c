#include "sort.h"
#include <stdlib.h>

/**
 * arr_max - array max int
 * @array: array
 * @size: size of array
 * Return: max size
 */
int arr_max(int *array, size_t size)
{
	int maxi;
	size_t i;

	maxi = array[0];
	for (i = 1; i < size; i++)
		if (array[i] > maxi)
			maxi = array[i];
	return (maxi);
}

/**
 * counting_sort - sorts array with Count sort algorithm
 * @array: array to sorted
 * @size: size of array
 */
void counting_sort(int *array, size_t size)
{
	int *arr, *o_arr, maxi, num;
	size_t i;

	if (size < 2 || !array)
		return;
	maxi = arr_max(array, size);

	arr = malloc(sizeof(size_t) * (maxi + 1));
	o_arr = malloc(sizeof(int) * size);

	for (i = 0; (int)i <= maxi; i++)
		arr[i] = 0;
	for (i = 0; i < size; i++)
	{
		num = array[i];
		arr[num] += 1;
	}
	for (i = 1; (int)i <= maxi; i++)
		arr[i] += arr[i - 1];
	print_array(arr, maxi + 1);
	for (i = 0; i < size; i++)
	{
		o_arr[arr[array[i]] - 1] = array[i];
		arr[array[i]]--;
	}
	for (i = 0; i < size; i++)
		array[i] = o_arr[i];

	free(o_arr);
	free(arr);
}
