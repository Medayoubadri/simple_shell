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
	int exit_status = 0;
	int command_status;

	while (status)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");
		input = read_input();
		if (input == NULL)
			break;
		args = parse_input(input);
		command_count++;
		if (args!= NULL)
		{
			command_status = execute_command(args, command_count);
			if (command_status != 1)
			{
				exit_status = command_status;
			}

			status = command_status;
		}
		free(input);
		free(args);
	}

	_exit(exit_status);
}
