#include "monty.h"
/**
 * f_swap - swaps the top two elements of the stack.
 * @head: the top of the stack
 * @line_number: the line number
 * Return: nothing
 */
void f_swap(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		fclose(bus.fp);
		_free(head);
		exit(EXIT_FAILURE);
	}
	if ((*head)->prev == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		fclose(bus.fp);
		_free(head);
		exit(EXIT_FAILURE);
	}

	temp = (*head)->prev;
	(*head)->next = temp;
	if (temp->prev != NULL)
	{
		(*head)->prev = temp->prev;
		(temp->prev)->next = *head;
	}
	else
		(*head)->prev = NULL;
	temp->prev = *head;
	temp->next = NULL;
	*head = temp;
}
