#include "shell.h"

/**
 * custom_strtok - Custom tokenizer function to split a string into tokens.
 * @str: The input string.
 * @delim: The delimiter characters.
 *
 * Return: Pointer to the next token, or NULL if no more tokens are found.
 */
char *custom_strtok(char *str, const char *delim)
{
	static char *next_token;
	char *current_token;

	if (str != NULL)
		next_token = str;

	if (next_token == NULL || *next_token == '\0')
		return (NULL);

	current_token = next_token;

	while (*next_token != '\0')
	{
		if (strchr(delim, *next_token) != NULL)
		{
			*next_token = '\0';
			next_token++;
			break;
		}
		next_token++;
	}

	if (*current_token == '\0')
		return (NULL);

	return (current_token);
}

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

	token = custom_strtok(input, " ");
	while (token != NULL)
	{
		tokens[i++] = token;
		if (i >= bufsize)
		{
			tokens = resize_tokens_array(tokens, &bufsize);
		}
		token = custom_strtok(NULL, " ");
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

