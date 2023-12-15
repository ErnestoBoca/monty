#include "monty.h"
/**
 * f_push - pushes the argument into the stack
 * @head: the top of the stack
 * @number: the current line number
 * Return: nothing
 */
void f_push(stack_t **head, unsigned int number)
{
	stack_t *newnode;
	int num, i = 0;

	if (bus.argument != NULL)
	{
		for (i = 0; bus.argument[i] != '\0'; i++)
		{
			if ((bus.argument[i] < 48 || bus.argument[i] > 57)
					&& bus.argument[i] != '-')
			{
				fprintf(stderr, "L%u: usage: push integer\n", number);
				fclose(bus.fp);
				_free(head);
				exit(EXIT_FAILURE);
			}
		}
	} else
	{
		fprintf(stderr, "L%u: usage: push integer\n", number);
		fclose(bus.fp);
		_free(head);
		exit(EXIT_FAILURE);
	}
	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	num = atoi(bus.argument);
	newnode->n = num;
	newnode->prev = NULL;
	newnode->next = NULL;
	if (*head != NULL)
	{
		(*head)->next = newnode;
		newnode->prev = *head;
	}
	*head = newnode;
}
