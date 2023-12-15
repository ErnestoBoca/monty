#include "monty.h"
/**
 * execute - tokenizes the read line and executes the function
 * @top: top of the queue
 * @line_number: the current line number of the file
 * Return: nothing
 */
void execute(unsigned int line_number, stack_t **top)
{
	instruction_t ops[] = {{"push", f_push}, {"pall", f_pall}, {"pint", f_pint},
				{NULL, NULL}};
	char *opcode;
	int i = 0;

	opcode = strtok(bus.line_content, " \t\n");
/*	printf("opcode: %s size: %ld\n", opcode, strlen(opcode)); */
	while (ops[i].opcode != NULL)
	{
		if (strcmp(ops[i].opcode, opcode) == 0)
		{
			bus.argument = strtok(NULL,  " \t\n");
			ops[i].f(top, line_number);
		/*	printf("%s %s %u\n", opcode, bus.argument, line_number); */
			break;
		}
		i++;
	}

	if (ops[i].opcode == NULL)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		fclose(bus.fp);
	/*	free(bus.line_content); */
		_free(top);
		exit(EXIT_FAILURE);
	}

}
