#include "monty.h"
/**
* main- runs the program
* @argc: number of arguments
* @argv: array containing arguments as strings
* Return: EXIT_SUCCESS
**/

int main(int argc, char *argv[])
{
	FILE *fd;
	char *line = NULL;
	char *opcode;
	char *n;
	unsigned int line_number = 0;
	stack_t *stack = NULL;
	size_t len = 0;
	ssize_t read;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	/*read = getline(&line, &len, fd);*/
	while ((read = getline(&line, &len, fd)) != -1)
	{
		line_number++;
		opcode = strtok(line, "\n ");
		if (opcode == NULL || strncmp(opcode, "#", 1) == 0)
			continue;
		if (strcmp(opcode, "push") == 0)
		{
			n = strtok(NULL, "\n ");
			push(&stack, line_number, n);
		}
		else
			xecutor(opcode, &stack, line_number, fd);
	}
	free(stack);
	free(line);
	free(fd);
	return (EXIT_SUCCESS);
}
