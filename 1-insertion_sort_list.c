#include "sort.h"

/**
 * insertion_sort_list -  sorts a doubly linked list of integers in ascending
 *@list: linked list
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *nex;

	if (!list || !(*list) || (*list)->next == NULL)
		return;
	temp = *list;
	nex = temp->next;

	while (temp->next != NULL)
	{
		if (temp->n > nex->n)
		{
			temp = change(temp, list);

			while (temp->prev)
			{
				if (temp->n < temp->prev->n)
					temp = change(temp->prev, list);
				else
					break;
			}
		}
		temp = temp->next;
		nex = temp->next;
	}
}
/**
 * change -  changes node position
 *@temp: temporal node
 *@list: linked list
 * Return: node
 */
listint_t *change(listint_t *temp, listint_t **list)
{
	listint_t *sig = NULL, *aux = NULL, *ant = NULL;

	aux = temp->next;
	sig = temp->next->next;
	ant = temp->prev;

	if (ant)
		ant->next = aux;
	if (ant == NULL)
		*list = aux;
	temp->prev = aux;
	temp->next = sig;
	aux->prev = ant;
	aux->next = temp;
	if (sig)
		sig->prev = temp;
	print_list(*list);
	return (aux);
}
