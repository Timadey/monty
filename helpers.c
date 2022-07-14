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
	char **tokens;
	char *token;
	unsigned int token_size = TOK_SIZE;
	unsigned int index = 0;

	if (line == NULL)
		return (NULL);
	tokens = malloc(token_size * sizeof(char *));
	check_malloc(tokens);
	printf("here");

	token = strtok(line, TOK_DELIM);
	while (token != NULL)
	{
		tokens[index] = token;
		token = strtok(NULL, TOK_DELIM);
		index++;
	}
	tokens[index] = token;
	return (tokens);
}
