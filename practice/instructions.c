#include "monty.h"
/**
 * push - opcode push pushes an element to the stack and print
 * the data pushed to the stdout
 * Usage: push <int>
 * @stack: the top of the stack
 * @line_number: current line number of the monty file
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *monty = *stack;
	extern stack_t *top;
	extern char *arg;
	int data;
	stack_t *new;

	if (arg == NULL || !is_int(arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	data = atoi(arg);

	new = malloc(sizeof(stack_t));
	check_malloc(new);
	new->n = data;
	new->prev = monty;
	new->next = NULL;

	if (monty == NULL)
	{
		top = new;
	}
	else
	{
		monty->next = new;
		top = new;
	}
}
/**
 * pall - prints all values on the stack starting, starting from the top of the stack
 * @stack: top of the stack
 * @line_number: current line number of the monty file
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	current = *stack;
	if (current == NULL)
		fprintf(stderr, "L:%d Error: can't print stack with null", line_number);
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->prev;
	}
}
