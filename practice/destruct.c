#include "monty.h"
/**
 * destructor - clean up memory after program execution
 * Return: void
 */
void destructor()
{
	extern char *line;
	extern char **tokens;
	extern stack_t *top;

	if (line)
		free(line);
	if (tokens)
		free(tokens);
	if (top)
		free_stack();
}
