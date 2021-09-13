#include "monty.h"
/**
*
*
*
*
*
*
**/
int executor(char *opcode, stack_t **stack, unsigned int line_number)
{
	int i;

		instruction_t opcodes[] = {
			{"push", push},
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
			(opcodes[i].f)(stack, line_number);
			return (EXIT_SUCCESS);
		}
	}
}