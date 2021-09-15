#include "monty.h"
/**
* add- adds node values
* @stack: pointer to 2x linked list
* @line_number: line number
* @opcode: tokenized opcode
* @fd: file descriptor
* Return: void
**/
void add(stack_t **stack, unsigned int line_number, char *opcode, FILE *fd)
{
	int sum = (*stack)->n;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free(opcode);
		free_list(*stack);
		fclose(fd);
		exit(EXIT_FAILURE);
	}
	pop(stack, line_number, opcode, fd);
	(*stack)->n += sum;
}
/**
* nop- does nothing
* @stack: pointer to 2x linked list
* @line_number: line number
* @opcode: tokenized opcode
* @fd: file descriptor
* Return: void
**/
void nop(stack_t **stack, unsigned int line_number, char *opcode, FILE *fd)
{
	(void) stack;
	(void) line_number;
	(void) opcode;
	(void) fd;
}
