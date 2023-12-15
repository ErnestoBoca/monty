#include "monty.h"
/**
 * _free - frees the memory used by the stack
 * @head: the top of the stack
 * Return: nothing
 */
void _free(stack_t **head)
{
	stack_t *temp;

	while (*head != NULL)
	{
		temp = *head;
		*head = (*head)->prev;
		free(temp);
	}
}
