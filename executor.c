#include "monty.h"
/**
* xecutor- executed opcodes
* @stack: pointer to 2x linked list
* @line_number: line number
* @opcode: tokenized opcode
* @fd: file descriptor
* Return: void
**/
int xecutor(char *opcode, stack_t **stack, unsigned int line_number, FILE *fd)
{
	int i;

		instruction_t opcodes[] = {
			{"pall", pall},
			{"pint", pint},
			{"pop", pop},
			{"swap", swap},
			{"add", add},
			{"nop", nop},
			{NULL,  NULL}
		};

	for (i = 0; opcodes[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)
		{
			(opcodes[i].f)(stack, line_number, opcode, fd);
			return (EXIT_SUCCESS);
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	free(opcode);
	free_list(*stack);
	fclose(fd);
	exit(EXIT_FAILURE);
}
