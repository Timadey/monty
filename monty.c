#include "monty.h"
FILE *file;
stack_t *top = NULL;
char **tokens = NULL;
char *line = NULL;
unsigned int line_number = 0;

/**
 * main - the main entry of the monty program
 * @argv: argument vector
 * @argc: argument count
 * Return: 0 on success, negative on failure
 */
int main(int argc, char **argv)
{
	size_t len = 0;
	ssize_t nread;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	tokens = malloc(TOK_SIZE * sizeof(char *));
	check_malloc(tokens);

	while ((nread = getline(&line, &len, file)) != -1)
	{
		printf("line %d: %s\n", line_number, line);
		if (line == NULL)
		{
			fail_exit(0);
		}
		tokens = tokenize_line(line);
		if (tokens == NULL)
			return (0);
		run_monty(tokens);
		/**
		  for (i = 0; i < 3; i++)
		  {
		  printf("	command: %s\n", tokens[i]);
		  }
		  */

		line_number++;
	}

	fclose(file);
	return (0);
}
