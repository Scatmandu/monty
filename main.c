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
	FILE *fp;
	char *line = NULL;
	char *opcode;
	int line_number = 0;
	stack_t *stack = NULL;
	size_t len = 0;
	ssize_t read = getline(&line, &len, fp);

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file \n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read != -1)
	{
		line_number++;
		opcode = strtok(line, "\n ");
		if (opcode == NULL)
			continue;
		/* function to find and execute functions */
	}
	free(stack);
	free(line);
	fclose(fp);
	return (EXIT_SUCCESS);
}
