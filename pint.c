#include "monty.h"
/**
 * f_pint -  prints the value at the top of the stack, followed by a new line
 * @head: head of the stack
 * @line_number: the line number
 * Return: nothing
 */
void f_pint(stack_t **head, unsigned int line_number)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		fclose(bus.fp);
		_free(head);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*head)->n);
}
