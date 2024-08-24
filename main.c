#include "shell.h"

/**
 * main - Simple shell main loop
 *
 * Return: Always 0
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	while (1)
	{
		printf("($) ");  /* Display prompt */
		nread = getline(&line, &len, stdin);  /* Read user input */

		if (nread == -1)
		{
			free(line);
			break;
		}

		/* Remove newline character from the end of the input */
		if (line[nread - 1] == '\n')
			line[nread - 1] = '\0';

		process_command(line);
	}

	return (0);
}

