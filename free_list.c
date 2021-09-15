#include "monty.h"
/**
* free_list- frees linked list node by node
* @head: pointer to the head of the list
* Return: void
**/
void free_list(stack_t *head)
{
	stack_t *node = head;
	stack_t *next;

	while (node != NULL)
	{
		next = node->next;
		free(node);
		node = next;
	}
}
