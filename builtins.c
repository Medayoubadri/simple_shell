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

