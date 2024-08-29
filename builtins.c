#include "shell.h"

/**
 * handle_exit - Handles the exit built-in command
 * @command: The command string (should be "exit")
 *
 * Description: Puts your shell to bed—peacefully or angrily
 *              based on how well you nailed the exit status.
 */
void handle_exit(char *command)
{
	char **args;
	int status = 0;

	args = tokey_slicer(command, " ");

	if (args[1] != NULL)
	{
		status = atoi(args[1]);
		if (status == 0 && strcmp(args[1], "0") != 0)
		{
			fprintf(stderr, "exit: %s: numeric argument required\n", args[1]);
			free_pointer_array(args);
			return;
		}
	}

	free_pointer_array(args);
	exit(status);
}
/**
 * handle_env - Handles the env built-in command
 * @command: The command string (should be "env")
 *
 * Description: spills out all the dirty secrets of your environment variables.
 *              Don’t like what you see? Tough luck—it's your environment.
 */
void handle_env(char *command)
{
	int i;

	if (strcmp(command, "env") == 0)
	{
		for (i = 0; environ[i] != NULL; i++)
		{
			printf("%s\n", environ[i]);
		}
	}
}

/**
 * handle_setenv - Initializes or modifies an environment variable
 * @command: The command string ("setenv VARIABLE VALUE")
 *
 * Description: Sets a new environment variable or updates an existing one.
 * Prints an error message to stderr on failure.
 */
void handle_setenv(char *command)
{
	char **args = tokey_slicer(command, " ");

	if (!args || !args[1] || !args[2])
	{
		fprintf(stderr, "setenv: Usage: setenv VARIABLE VALUE\n");
		if (args)
			free_pointer_array(args);
		return;
	}

	if (setenv(args[1], args[2], 1) != 0)
	{
		perror("setenv");
	}
	free_pointer_array(args);
}

/**
 * handle_unsetenv - Removes an environment variable
 * @command: The command string ("unsetenv VARIABLE")
 *
 * Description: Removes an environment variable.
 *              Prints an error message to stderr on failure.
 */
void handle_unsetenv(char *command)
{
	char **args = tokey_slicer(command, " ");

	if (!args || !args[1])
	{
		fprintf(stderr, "unsetenv: Usage: unsetenv VARIABLE\n");
		if (args)
			free_pointer_array(args);
		return;
	}

	if (unsetenv(args[1]) != 0)
	{
		perror("unsetenv");
	}
	free_pointer_array(args);
}

/**
 * handle_echo - Handles the echo built-in command
 * @command: The command string ("echo [arguments]")
 *
 * Description: Ever had a conversation with yourself? This function lets
 * the shell do just that. If you babble nonsense well, it'll echo that back.
 * Shells aren't picky—they repeat what they're told.
 */
void handle_echo(char *command)
{
    char **args = tokey_slicer(command, " ");
    char *value;
    int i;

    for (i = 1; args[i]; i++)
    {
        if (args[i][0] == '$')
        {
            value = getenv(args[i] + 1);
            if (value)
                printf("%s ", value);
            else
                printf("%s ", args[i]);
        }
        else
        {
            printf("%s ", args[i]);
        }
    }
    printf("\n");
    free_pointer_array(args);
}
