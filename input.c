#include "shell.h"

/**
 * read_input - Reads a line of input from stdin.
 *
 * Return: The input string.
 */
char *read_input(void)
{
	char *input = NULL;
	size_t bufsize = 0;
	ssize_t nread;

	nread = getline(&input, &bufsize, stdin);
	if (nread == -1)
	{
		free(input);
		return (NULL);
	}

	if (input[nread - 1] == '\n')
		input[nread - 1] = '\0';

	return (input);
}

/**
 * parse_input - Parses the input into arguments.
 * @input: The input string.
 *
 * Return: An array of arguments.
 */
char **parse_input(char *input)
{
	int bufsize = 64, i = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		perror("allocation error");
		exit(EXIT_FAILURE);
	}

	token = strtok(input, " ");
	while (token != NULL)
	{
		tokens[i++] = token;

		if (i >= bufsize)
		{
			bufsize += 64;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				perror("allocation error");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, " ");
	}
	tokens[i] = NULL;
	return (tokens);
}

