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

	if (line != NULL)
		free(line);
	if (tokens != NULL)
		free(tokens);
	if (top != NULL)
		free_stack();
}
/**
 * fail_exit - clean and exit the program on error
 * @status: exit status
 * Return: void
 */
void fail_exit(int status)
{
	extern FILE *file;

	fclose(file);
	destructor();
	exit(status);
}
