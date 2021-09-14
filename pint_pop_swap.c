#include "monty.h"
/**
*
*
*
*
*
**/
void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL && *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", *stack->n);
}

/**
 *
 *
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	tmp=*stack;
	if (tmp == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (tmp->next = NULL)
	{
		*stack = NULL;
		free(tmp);
	}
}

/**
 *
 *
 *
 */
void swap(stack_t **stack, unsigned int line_number)
{

}
