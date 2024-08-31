#include "shell.h"

/**
 * shell_exit - Exits the shell.
 * @args: The arguments array (unused).
 *
 * Return: 0 to terminate the shell.
 */
int shell_exit(char **args)
{
	(void)args; /* Avoid unused parameter warning */
	return (0);
}

/**
 * print_env - Prints the current environment variables.
 */
int print_env(char **args)
{
    char **env = environ;

    (void)args; /* Avoid unused parameter warning */

    while (*env)
    {
        printf("%s\n", *env);
        env++;
    }

    return (1);
}
