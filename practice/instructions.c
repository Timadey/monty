#include "monty.h"
/**
 * push - opcode push pushes an element to the stack and print
 * the data pushed to the stdout
 * Usage: push <int>
 * @data: the integer to push to the stack
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number);
{
	stack_t *monty = *stack;
	extern stack_t *top;
	extern int data;
	stack_t *current;
	stack_t *new = malloc(sizeof(stack_t));
	check_malloc(new);

	new->n = data;
	new->prev = top;
	new->next = NULL;

	if (monty == NULL)
	{
		monty = new;
		top = new;
		return (new->n);
	}
	else
	{
		current = monty;
		while (current->next != NULL)
			current = current->next;
		current->next = new;
		top = new;
		return (new->n);
	}
}
