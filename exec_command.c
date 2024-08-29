#include "shell.h"

/**
 * execute_command - Executes a command using execve.
 * @command: The command to execute.
 */
void execute_command(char *command)
{
	pid_t pid;
	int status;
	char *argv[2];

	argv[0] = command;
	argv[1] = NULL;

	/* Check if command contains a '/' indicating a path */
	if (strchr(command, '/') == NULL)
	{
		/* Print error if command is not a path */
		char *error_msg = ": 1: command not found\n";
		write(STDERR_FILENO, command, strlen(command));
		write(STDERR_FILENO, error_msg, strlen(error_msg));
		return;
	}

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execve(command, argv, NULL) == -1)
		{
			perror(command); /* Print error if execve fails */
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}
}

