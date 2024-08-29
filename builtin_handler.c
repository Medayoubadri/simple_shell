#include "shell.h"

/**
 * handle_builtin - Checks for and handles built-in commands.
 * @args: The arguments array.
 *
 * Return: 0 if a built-in command was executed and the shell should exit,
 *         1 if no built-in was found or executed.
 */
int handle_builtin(char **args)
{
	if (strcmp(args[0], "exit") == 0)
	{
		exit(0);  /* Exits the shell */
	}

	if (strcmp(args[0], "env") == 0)
	{
		print_env();
		return (1);
	}

	/* Add more built-ins as needed */
	return (1);
}

/**
 * print_env - Prints the current environment.
 */
void print_env(void)
{
	char **env = environ;

	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
}

