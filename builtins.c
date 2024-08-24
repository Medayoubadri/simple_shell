#include "shell.h"

/**
 * handle_exit - Handles the exit built-in command
 * @command: The command string (should be "exit")
 *
 * Description: The most merciful command in the shell—this one puts an
 *              end to all. No arguments, no delays, just END.
 */
void handle_exit(char *command)
{
	if (strcmp(command, "exit") == 0)
	{
		free(command);
		exit(0);  /* Goodbye, cruel world */
	}
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
