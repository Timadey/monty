#include "monty.h"
unsigned int status = 0;
char *arg = NULL;

/**
 * run_monty - responsible for running the monty commands
 * @tokens: the tokenized line
 * Return: void, exit on error
 */
void run_monty(char **tokens)
{
	unsigned int i = 0;
	extern unsigned int line_number;
	extern stack_t *top;
	void (*op_func)(stack_t **stack, unsigned int line_number) = NULL;

	while (tokens[i] != NULL)
	{
		op_func = get_op_func(tokens[i]);
		if (op_func == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, tokens[i]);
			fail_exit(EXIT_FAILURE);
		}
		arg = tokens[++i];
		op_func(&top, line_number);
		i++;
	}
}
