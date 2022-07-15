#include "monty.h"
/**
 * main - the main entry of the monty program
 * @argv: argument vector
 * @argc: argument count
 * Return: 0 on success, negative on failure
 */
int main(int argc, char **argv)
{
	FILE *file;
	size_t len = 0;
	ssize_t nread;
	size_t line_number;
	char **tokens = NULL;
	char *line = NULL;
	int i;
	
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
	line_number = 0;

	while ((nread = getline(&line, &len, file)) != -1)
	{
		printf("line %ld: %s\n", line_number, line);
		if (line == NULL)
			return (0);
		tokens = tokenize_line(line);
		run_monty(tokens);
		for (i = 0; i < 3; i++)
		{
			printf("	command: %s\n", tokens[i]);
		}

		line_number++;
	}

	fclose(file);
	return (0);
}
