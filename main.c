#include "monty.h"
/**
*
*
*
*
*
**/

int main(int argc, char *argv[])
{
	FILE *fd;
	char *line = NULL;
	char *opcode;
	char *n;
	int line_number = 0;
	stack_t *stack = NULL;
	size_t len = 0;
	ssize_t read = getline(&line, &len, fd);

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file \n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read != -1)
	{
		line_number++;
		opcode = strtok(line, " \n\t");
		if (opcode == NULL || strncmp(opcode, "#", 1) == 0)
			continue;
		if (strcmp(opcode, "push") == 0)
		{
			n = strtok(NULL, " \n\t");
			push(&stack, line_number, n);
		}
		else
			executor(opcode, &stack, line_number);
	}
	free(stack);
	free(line);
	fclose(fd);
	return (EXIT_SUCCESS);
}
