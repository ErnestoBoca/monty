#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct bus_t - carries values throughout the program
 * @argument: argument to the opcode
 * @fp: pointer to the file that conteins the morty code
 * @line_content: the content of the current line
 *
 * Description: it is used to get the argument
 * close the file pointer and free the line_content pointer
 */
typedef struct bus_t
{
	char *argument;
	FILE *fp;
	char *line_content;
} bus_t;
extern bus_t bus;

void execute(unsigned int line_number, stack_t **top);
void f_push(stack_t **head, unsigned int number);
void f_pall(stack_t **top, unsigned int line_number);
void _free(stack_t **head);
void f_pint(stack_t **head, unsigned int line_number);
#endif
