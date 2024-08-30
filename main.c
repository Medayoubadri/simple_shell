#include "shell.h"

/**
 * main - Entry point of the simple shell
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char *input;
	char **args;
	int status = 1;

	while (status)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");

		input = read_input();
		if (input == NULL)
		{
			if (isatty(STDIN_FILENO))
				printf("\n");
			break;
		}

		args = parse_input(input);
		if (args == NULL)
		{
			free(input);
			continue;
		}

		status = execute_command(args);

		free(input);
		free(args);
	}

	return (0);
}

