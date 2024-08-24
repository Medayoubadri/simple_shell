#include "shell.h"

/**
 * execute_command - Executes a command using execve
 * @command: The command to execute
 */
void execute_command(char *command)
{
	char *argv[64];
	char *token;
	int i = 0;

	token = strtok(command, " ");
	while (token != NULL && i < 63)
	{
		argv[i] = token;
		token = strtok(NULL, " ");
		i++;
	}
	argv[i]  = NULL;

	if (execve(command, argv, NULL) == -1)
		handle_error(command);
}

