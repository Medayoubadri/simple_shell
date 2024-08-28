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
			free_tokens(args);
			return;
		}
	}

	free_tokens(args);
	exit(status);
}
/**
 * handle_env - Handles the env built-in command
 * @command: The command string (should be "env")
 *
 * Description: Spits out all the environment variables. Sometimes,
 *              you just need to see the mess your shell is living in.
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
