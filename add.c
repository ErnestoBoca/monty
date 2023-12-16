#include "monty.h"
/**
 * f_add - swaps the top two elements of the stack.
 * @head: the top of the stack
 * @line_number: the line number
 * Return: nothing
 */
void f_add(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		fclose(bus.fp);
		_free(head);
		exit(EXIT_FAILURE);
	}
	if ((*head)->prev == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		fclose(bus.fp);
		_free(head);
		exit(EXIT_FAILURE);
	}

	temp = *head;
	*head = (*head)->prev;
	(*head)->n += temp->n;
	(*head)->next = NULL;
	free(temp);
}
