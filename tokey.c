#include "shell.h"

/**
 * count_the_mess - Counts the number of tokens in a string
 * @str: The input string
 * @delim: The delimiter string
 *
 * Return: The number of tokens found
 */
int count_the_mess(char *str, const char *delim)
{
	int count = 0;
	char *temp = str;

	while (*temp)
	{
		while (*temp && strchr(delim, *temp)) /* Skip delimiters */
			temp++;
		if (*temp)
		{
			count++;
			while (*temp && !strchr(delim, *temp)) /* Skip token */
				temp++;
		}
	}
	return (count);
}

/**
 * tokey_slicer - Splits a command string into tokens
 * @command: The command string to tokenize
 * @delim: The delimiter string
 *
 * Return: An array of tokens
 */
char **tokey_slicer(char *command, const char *delim)
{
	int token_count = count_the_mess(command, delim);
	char **tokens = malloc((token_count + 1) * sizeof(char *));
	char *token;
	int i = 0;

	if (!tokens)
		return (NULL);

	while (*command)
	{
		while (*command && strchr(delim, *command)) /* Skip delimiters */
			command++;
		if (*command)
		{
			token = command;
			while (*command && !strchr(delim, *command)) /* Find end of token */
				command++;
			if (*command)
			{
				*command = '\0';
				command++;
			}
			tokens[i++] = strdup(token);
		}
	}
	tokens[i] = NULL;
	return (tokens);
}

