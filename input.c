#include "shell.h"

/**
 * read_input - Reads a line of input from stdin.
 *
 * Return: The input string.
 */
char *read_input(void)
{
	char *input = NULL;
	ssize_t nread;
	size_t len = 0;

	nread = getline(&input, &len, stdin);
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
 * trim_whitespace - Removes leading and trailing whitespaces from a string.
 * @str: The string to trim.
 *
 * Return: Pointer to the trimmed string.
 */
char *trim_whitespace(char *str)
{
	char *end;

	while (*str == ' ')
		str++;

	if (*str == 0)
		return (str);

	end = str + strlen(str) - 1;
	while (end > str && *end == ' ')
		end--;

	*(end + 1) = '\0';

	return (str);
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

	input = trim_whitespace(input);

	if (strlen(input) == 0)
	{
		free(tokens);
		return (NULL);
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

