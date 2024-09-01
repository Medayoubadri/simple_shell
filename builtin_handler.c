#include "shell.h"

/**
 * handle_builtin - Checks for and handles built-in commands.
 * @args: The arguments array.
 *
 * Return: 0 if a built-in command was executed and the shell should exit,
 *         1 if no built-in was found or executed.
 */
int handle_builtin(char **args, int *exit_status)
{
	if (strcmp(args[0], "exit") == 0)
	{
		return (shell_exit(args, exit_status));
	}

	if (strcmp(args[0], "env") == 0)
	{
		print_env(args);
		return (1);
	}

	return (-1);
}

