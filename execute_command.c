#include "shell.h"

/**
 * execute_command - Executes a command using execve
 * @command: The command to execute
 *
 * Description: This function is on a mission to execute your command.
 * If it fails, the shell will self-destruct (JK, it’ll just print an error).
 */
void execute_command(char *command)
{
	char *argv[64];
	char *cmd_path;
	char *token;
	int i = 0;

	/* Tokenize the command string into arguments */
	token = strtok(command, " ");
	while (token != NULL && i < 63)
	{
		argv[i] = token;
		token = strtok(NULL, " ");
		i++;
	}
	argv[i] = NULL;

	/* Find the command in PATH */
	cmd_path = find_command_path(argv[0]);
	if (!cmd_path)
	{
		handle_error(argv[0]);
		return;
	}

	/* Execute the command */
	if (fork() == 0)
	{
		if (execve(cmd_path, argv, NULL) == -1)
			handle_error(argv[0]);
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}

