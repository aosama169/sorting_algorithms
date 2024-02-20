#include "sort.h"

/**
 * get_digit - gets digit from a num
 * @number: integer
 * @digit: digit position index
 *
 * Return: digit value at index
**/
int get_digit(long number, int digit)
{
	long i = 0L, pows = 1L, ret;

	for (i = 0; i < digit; i++)
		pows *= 10L;
	ret = ((number / pows) % 10);
	return (ret);
}

/**
 * radix_pass - sorts by radix algorithm
 * @array: integer array to sort
 * @size: size of array
 * @digit: current digit to check
 * @new_array: target array of same size
 *
 * Return: void.
 */
int radix_pass(int *array, ssize_t size, int digit, int *new_array)
{
	ssize_t i;
	int bcts[10] = {0};

	for (i = 0; i < size; i++)
		bcts[get_digit(array[i], digit)]++;
	for (i = 1; i <= 9; i++)
		bcts[i] += bcts[i - 1];
	for (i = size - 1; i > -1; i--)
		new_array[bcts[get_digit(array[i], digit)]-- - 1] = array[i];
	return (1);
}

/**
 * radix_sort - sorts by radix algorithm
 * @size: size of array
 * @array: int array to sorted
 *
 * Return: gap size
 */
void radix_sort(int *array, size_t size)
{
	int *old_array, *new_array, *temp_ptr, *ptr, max = 0;
	size_t i, sct = 1;

	if (!array || size < 2)
		return;

	for (i = 0; i < size; i++)
		if (array[i] > max)
			max = array[i];
	while (max /= 10)
		sct++;
	old_array = array;
	new_array = ptr = malloc(sizeof(int) * size);
	if (!new_array)
		return;
	for (i = 0; i < sct; i++)
	{
		radix_pass(old_array, (ssize_t)size, i, new_array);
		temp_ptr = old_array;
		old_array = new_array;
		new_array = temp_ptr;
		print_array(old_array, size);
	}
	for (i = 0; i < size; i++)
		array[i] = old_array[i];
	free(ptr);
}
