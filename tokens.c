#include "shell.h"

/**
 * tokenize_input - Tokenizes the input string into arguments.
 * @input: The input string.
 * @bufsize: Initial buffer size for tokens array.
 *
 * Return: An array of tokens.
 */
char **tokenize_input(char *input, int bufsize)
{
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;
	int i = 0;

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
			tokens = resize_tokens_array(tokens, &bufsize);
		}
		token = strtok(NULL, " ");
	}
	tokens[i] = NULL;
	return (tokens);
}

/**
 * resize_tokens_array - Resizes the tokens array if needed.
 * @tokens: The current tokens array.
 * @bufsize: Pointer to the current buffer size.
 *
 * Return: A resized array of tokens.
 */
char **resize_tokens_array(char **tokens, int *bufsize)
{
	*bufsize += 64;
	tokens = realloc(tokens, *bufsize * sizeof(char *));
	if (!tokens)
	{
		perror("allocation error");
		exit(EXIT_FAILURE);
	}
	return (tokens);
}

