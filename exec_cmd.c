#include "shell.h"

/**
 * execute_command - Executes a command, checking PATH if necessary.
 * @args: The arguments array.
 *
 * Return: 1 if the shell should continue running, 0 if it should terminate.
 */
int execute_command(char **args)
{
	char *command_path;

	/* Handle built-in commands */
	if (handle_builtin(args) == 0)
		return (0);

	/* Resolve the command path */
	command_path = resolve_command(args[0]);
	if (!command_path)
	{
		print_error(args[0], ENOENT);
		return (1);
	}

	/* Fork and execute the command */
	fork_and_execute(command_path, args);

	if (command_path != args[0])
		free(command_path);

	return (1);
}

/**
 * resolve_command - Resolves the full path of a command.
 * @command: The command to resolve.
 *
 * Return: The full path if found, NULL if not found.
 */
char *resolve_command(char *command)
{
	char *command_path = NULL;

	if (strchr(command, '/') != NULL)
	{
		if (access(command, X_OK) == 0)
			return (command);
	}
	else
	{
		command_path = find_in_path(command);
		if (command_path)
			return (command_path);
	}

	return (NULL);
}

/**
 * fork_and_execute - Forks and executes a command.
 * @command_path: The resolved command path.
 * @args: The arguments array.
 */
void fork_and_execute(char *command_path, char **args)
{
	pid_t pid = fork();
	int status;

	if (pid == 0)
	{
		if (execve(command_path, args, NULL) == -1)
		{
			print_error(args[0], errno);
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		perror("fork failed");
	}
	else
	{
		waitpid(pid, &status, 0);
	}
}
