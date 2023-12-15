#include "monty.h"
/**
 * f_pop - removes the top element of the stack.
 * @head: the top of the stack
 * @line_number: the line number
 * Return: nothing
 */
void f_pop(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		fclose(bus.fp);
		_free(head);
	}

	temp = *head;
	*head = (*head)->prev;
	if (*head != NULL)
		(*head)->next = NULL;
	free(temp);
}
