#include "shell.h"

/**
 * shell_exit - Exits the shell.
 * @args: The arguments array (unused).
 *
 * Return: 0 to terminate the shell.
 */
int shell_exit(char **args, int *exit_status, int command_count)
{
	int i;

	if (args[1] != NULL)
	{
		for (i = 0; args[1][i] != '\0'; i++)
		{
			if (!isdigit(args[1][i]))
			{
				fprintf(stderr, "./hsh: %d: exit: Illegal number: %s\n", command_count, args[1]);
				*exit_status = 2;
				return (1);
			}
		}
		*exit_status = atoi(args[1]);
	}

	_exit(*exit_status);
}

/**
 * print_env - Prints the current environment variables.
 */
int print_env(char **args)
{
	char **env = environ;

	(void)args;

	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}

	return (1);
}

