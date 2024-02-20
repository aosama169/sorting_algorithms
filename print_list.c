#include <stdio.h>
#include "sort.h"

/**
 * print_list - Prints list of integers
 *
 * @list: The list to print
 */
void print_list(const listint_t *list)
{
	int ix;

	ix = 0;
	while (list)
	{
		if (ix > 0)
			printf(", ");
		printf("%d", list->n);
		++ix;
		list = list->next;
	}
	printf("\n");
}
