#include "monty.h"
/**
 * f_pall -  prints all the values on the stack,
 * starting from the top of the stack.
 * @top: the top os the stack
 * @line_number: the current line number
 * Return: nothing
 */
void f_pall(stack_t **top, unsigned int line_number)
{
	stack_t *temp = *top;
	(void)line_number;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->prev;
	}

}
