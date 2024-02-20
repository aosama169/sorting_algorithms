#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - Prints an array of int
 *
 * @array: The array to print
 * @size: Num of elements in array
 */
void print_array(const int *array, size_t size)
{
	size_t i;

	i = 0;
	while (array && i < size)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
		++i;
	}
	printf("\n");
}
