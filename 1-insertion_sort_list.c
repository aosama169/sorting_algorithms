#include "sort.h"
/**
* insertion_sort_list - insert sort algorithm
* @list: linked list to be sorted
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *tmp;
	int ct;

	if (!list)
		return;
	tmp = *list;
	while (tmp)
	{
		while (tmp)
		{
			if (tmp->next)
			{
				if (tmp->n > tmp->next->n)
				{
					ct = tmp->n;
					*(int *)&tmp->n = tmp->next->n;
					*(int *)&tmp->next->n = ct;
					tmp = *list;
					print_list(*list);
					break;
				}
			}
			tmp = tmp->next;
		}
	}
}
