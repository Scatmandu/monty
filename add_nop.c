#include "monty.h"
/**
*
*
*
*
*
**/
void add(stack_t **stack, unsigned int line_number)
{
	int sum = (*stack)->n;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	pop(stack, line_number);
	(*stack)->n += sum;
}

void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
