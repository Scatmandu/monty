#include "monty.h"
/**
 * push - Function that pushes elements to the stack
 * @stack: Pointer for head of the stack
 * @line_number: Line number for the file
 * @n: Int variable
 * Return: New element address
 */
void push(stack_t **stack, unsigned int line_number, int n)
{
	stack_t *new;
	stack_t *h = *stack;

	if (stack == NULL)
	{
		fprintf(stderr) /* Need help finishing this part */
		exit(EXIT_FAILURE);
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		exit(EXIT_FAILURE);
	new->prev = NULL;
	new->n = n;
	new->next = *stack;

	if (*stack)
		h->prev = new;
	*stack = new;
}

/**
 * pall - function that prints all values on the stack
 * @stack: Pointer for head of the stack
 * @line_number: Line number for the file
 * Return: Void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *h = *stack;
	(void)line_number;

	while (h)
	{
		printf("%d", h->n);
		h = h->next;
	}
}
