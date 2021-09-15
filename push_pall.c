#include "monty.h"
/**
 * push - Function that pushes elements to the stack
 * @stack: Pointer for head of the stack
 * @line_number: Line number for the file
 * @n: Int variable
 * Return: New element address
 */
void push(stack_t **stack, unsigned int line_number, char *n)
{
	stack_t *new;
	int i;

	if (n == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = atoi(n);
	new->next = NULL;
	new->prev = NULL;

	if (*stack)
	{
		new->next = *stack;
		(*stack)->prev = new;
	}
	*stack = new;
}

/**
 * pall - function that prints all values on the stack
 * @stack: Pointer for head of the stack
 * @line_number: Line number for the file
 * @opcode: tokenized opcode
 * @fd: file descriptor
 * Return: Void
 */
void pall(stack_t **stack, unsigned int line_number, char *opcode, FILE *fd)
{
	stack_t *h = *stack;
	(void) line_number;
	(void) opcode;
	(void) fd;

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
