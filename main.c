#include "shell.h"

void free_tokens(char **tokens)
{
	if (tokens != NULL)
	{
		free(tokens);
	}
}
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

	if (getenv("LANG") == NULL)
		setenv("LANG", "en_US.UTF-8", 1);
	if (getenv("LC_COLLATE") == NULL)
		setenv("LC_COLLATE", "en_US.UTF-8", 1);

	while (status)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");
		input = read_input();
		if (input == NULL)
			break;
		args = parse_input(input);
		command_count++;
		if (args != NULL)
		{
			command_status = execute_command(args, command_count);

			if (strcmp(args[0], "exit") == 0)
			{
				status = 0;
			}
			else
			{
				exit_status = command_status;
			}

			free_tokens(args);
		}
		free(input);
	}

	_exit(exit_status);
}
