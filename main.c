#include "monty.h"

bus_t bus = {NULL, NULL, NULL};
/**
 * isEmpty - checks whether a line is empty or not
 * @line: the line
 * Return: 1 if the line is empty otherwise return 0
 */
int isEmpty(char *line)
{
	while (*line)
	{
		if (*line != ' ' && *line != '\t' && *line != '\n' && *line != '\r')
			return (0);
		line++;
	}

	return (1);
}

/**
 * main - The entry function of the program
 * @argc: the number of arguments of the function
 * @argv: the vector of arguments
 * Return: 0 on succces
 */
int main(int argc, char *argv[])
{
	FILE *fp;
	char line[1024];
	unsigned int line_number;
	stack_t *top = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: can't open file %s\n", argv[1]);
		exit(0);
	}

	bus.fp = fp;
	line_number = 1;
	while (fgets(line, 1024, fp))
	{
		if (!isEmpty(line))
		{
		/*	printf("LInha: %s size: %ld\n", line, strlen(line)); */
			bus.line_content = line;
			execute(line_number, &top);
		}
		line_number++;
	}

	fclose(fp);
	_free(&top);


	return (0);
}
