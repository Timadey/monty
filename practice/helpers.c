#include "monty.h"
/**
 * check_malloc - checks if a memory allocation fails
 * @mem: the pointer to the memory allocated
 * Return: exit with error message if failed
 */
void check_malloc(void *mem)
{
	if (mem == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
}
/**
 * tokenize_line - parse the line of a monty file into tokens
 * Return: a buffer containing the tokenised line
 */
char **tokenize_line(char *ln)
{
	char *line = ln;
	extern char **tokens;
	char *token;
	unsigned int token_size = TOK_SIZE;
	unsigned int index = 0;

	if (line == NULL)
		return (NULL);
	if (tokens == NULL)
	{
		tokens = malloc(token_size * sizeof(char *));
		check_malloc(tokens);
	}

	token = strtok(line, TOK_DELIM);
	while (index < token_size)
	{
		tokens[index] = token;
		token = strtok(NULL, TOK_DELIM);
		index++;
	}
	tokens[index] = token;
	return (tokens);
}
/**
 * is_int - check if the string passed is an integer
 * @str: the string to check
 * Return: 1 if true 0 if false
 */
int is_int(char *str)
{
	int dig;

	if (str == NULL)
		return (0);
	if (*str == '-')
		str++;
	dig = *str;
	while (dig != '\0')
	{
		if (!isdigit(dig))
			return (0);
		dig = *(str++);
	}
	return (1);
}
/**
 * free_stack - free a stack_t stack
 * Return: void
 */
void free_stack()
{
	extern stack_t *top;
	stack_t *prev;

	if (top == NULL)
		return;
	while (top != NULL)
	{
		prev = top;
		top = top->prev;
		free(prev);
	}
}
