#include "monty.h"
/**
* pint- prints value at top of stack with newline
* @stack: pointer to 2x linked list
* @line_number: line number
* @opcode: tokenized opcode
* @fd: file descriptor
* Return: void
**/
void pint(stack_t **stack, unsigned int line_number, char *opcode, FILE *fd)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_list(*stack);
		free(opcode);
		fclose(fd);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
* pop- removes top element of the stack
* @stack: pointer to 2x linked list
* @line_number: line number
* @opcode: tokenized opcode
* @fd: file descriptor
* Return: void
**/
void pop(stack_t **stack, unsigned int line_number, char *opcode, FILE *fd)
{
	stack_t *tmp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_list(*stack);
		free(opcode);
		fclose(fd);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next;
	free(*stack);
	*stack = tmp;
}

/**
* swap- swaps top two elements of the stack
* @stack: pointer to 2x linked list
* @line_number: line number
* @opcode: tokenized opcode
* @fd: file descriptor
* Return: void
**/
void swap(stack_t **stack, unsigned int line_number, char *opcode, FILE *fd)
{
	stack_t *tmp, *store;
	int n;

	if (*stack == NULL ||
	    (((*stack)->prev == NULL) && (*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_list(*stack);
		free(opcode);
		fclose(fd);
		exit(EXIT_FAILURE);
	}
	for (tmp = *stack; tmp->prev; tmp = tmp->prev)
	{
	}
	store = tmp->next;
	n = tmp->n;
	tmp->n = store->n;
	store->n = n;
}
