#include "shell.h"

/**
 * main - Entry point of the simple shell.
 *
 * Return: Always 0.
 */
int main(void)
{
	char *command = NULL;
	size_t len = 0;
	ssize_t nread;

	while (1)
	{
		prompt();
		nread = getline(&command, &len, stdin);
		if (nread == -1)
		{
			if (feof(stdin))
			{
				free(command);
				write(STDOUT_FILENO, "\n", 1); /* Add a new line on exit */
				exit(0); /* Ctrl+D was pressed */
			}
			else
			{
				perror("getline");
				free(command);
				exit(EXIT_FAILURE);
			}
		}

		/* Remove newline character from the end */
		if (command[nread - 1] == '\n')
			command[nread - 1] = '\0';

		/* Skip empty lines */
		if (strlen(command) == 0)
			continue;

		execute_command(command);
	}

	free(command);
	return (0);
}

/**
 * prompt - Displays the prompt.
 */
void prompt(void)
{
	write(STDOUT_FILENO, "$ ", 2);
}

