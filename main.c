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
			break;
		args = parse_input(input);
		status = execute_command(args);
		free(input);
		free(args);
	}

	return (0);
}

