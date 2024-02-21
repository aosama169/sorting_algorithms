#include "deck.h"
/**
 * aux_num_fun - turn into integer card value
 * @head_tmp1: pointer to list
 * Return: integer rep
 **/
int aux_num_fun(deck_node_t *head_tmp1)
{
	int temp, j;
	int num[13] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
	char val[13] = {'A', '2', '3', '4', '5', '6', '7',
		'8', '9', '1', 'J', 'Q', 'K'};

	for (j = 0; j < 13; j++)
	{
		if (head_tmp1->card->value[0] == val[j])
			temp = num[j];
	}

	return (temp);
}
/**
 * num_sort - sorts a doubly linked list of integers
 * @list: pointer to list head
 * Return: no return
 **/
void num_sort(deck_node_t **list)
{
	deck_node_t *head_tmp1, *head_tmp2, *aux1, *aux2;
	int cter = 0, i, temp1, temp2;
	unsigned int k;

	head_tmp1 = *list;
	head_tmp2 = *list;
	for (i = 0; i < 4; i++)
	{ k =  head_tmp1->card->kind;
		while (head_tmp1->next && head_tmp1->next->card->kind == k)
		{
			temp1 = aux_num_fun(head_tmp1);
			temp2 = aux_num_fun(head_tmp1->next);
			cter = 0;
			head_tmp2 = head_tmp1;
			while (head_tmp2 && head_tmp2->card->kind == k && temp1 > temp2)
			{
				aux1 = head_tmp2;
				aux2 = head_tmp2->next;
				aux1->next = aux2->next;
				if (aux2->next)
					aux2->next->prev = aux1;
				aux2->prev = aux1->prev;
				aux2->next = aux1;
				aux1->prev = aux2;
				if (aux2->prev)
					aux2->prev->next = aux2;
				head_tmp2 = aux2->prev;
				if (!aux2->prev)
					*list = aux2;
				cter = 1;
				if (!head_tmp2)
					break;
				temp1 = aux_num_fun(head_tmp2);
				temp2 = aux_num_fun(head_tmp2->next);
			}
			if (cter == 0)
				head_tmp1 = head_tmp1->next;
		}
		head_tmp1 = head_tmp1->next;
	}
}
/**
 * kind_sort - sorts doubly linked list of integers
 * in ascending order using Insertion sort ailgorithm
 * @list: pointer to list head
 * Return: no return
 **/
void kind_sort(deck_node_t **list)
{
	deck_node_t *head_tmp1, *head_tmp2, *aux1, *aux2;
	int cter;

	if (list)
	{
		head_tmp1 = *list;
		head_tmp2 = *list;
		while (list && head_tmp1->next)
		{
			if (head_tmp1->next)
			{
				cter = 0;
				head_tmp2 = head_tmp1;
				while (head_tmp2 && head_tmp2->card->kind > head_tmp2->next->card->kind)
				{
					aux1 = head_tmp2;
					aux2 = head_tmp2->next;
					aux1->next = aux2->next;
					if (aux2->next)
						aux2->next->prev = aux1;
					if (aux2)
					{
						aux2->prev = aux1->prev;
						aux2->next = aux1;
					}
					if (aux1)
						aux1->prev = aux2;
					if (aux2->prev)
						aux2->prev->next = aux2;
					head_tmp2 = aux2->prev;
					if (!aux2->prev)
						*list = aux2;
					cter = 1;
				}
			}
			if (cter == 0)
				head_tmp1 = head_tmp1->next;
		}
	}
}
/**
 * sort_deck - sorts a deck of cards
 * @deck: ponter to deck
 * Return: nothing
 *
 **/
void sort_deck(deck_node_t **deck)
{
	if (deck)
	{
		kind_sort(deck);
		num_sort(deck);
	}
}