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
	int command_count = 0;

	while (status)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");
		input = read_input();
		if (input == NULL)
			break;
		args = parse_input(input);
		command_count++;
		status = execute_command(args, command_count);
		free(input);
		free(args);
	}

	return (0);
}
