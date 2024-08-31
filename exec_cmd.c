#include "shell.h"

/**
 * execute_command - Executes a command, checking PATH if necessary.
 * @args: The arguments array.
 * @command_count: The count of commands executed so far.
 *
 * Return: 1 if the shell should continue running, 0 if it should terminate.
 */
int execute_command(char **args, int command_count)
{
	char *command_path;
	int builtin_status;
	int exec_status;

	if (args == NULL || args[0] == NULL)
		return (1);

	/* Handle built-in commands */
	builtin_status = handle_builtin(args);
	if (builtin_status == 0)
	{
		return (0);
	}
	else if (builtin_status == 1)
	{
		return (1);
	}

	/* Resolve the command path */
	command_path = resolve_command(args[0]);
	if (!command_path)
	{
		print_error(args[0], ENOENT, command_count);
		return (127);
	}

	/* Fork and execute the command */
	exec_status = fork_and_execute(command_path, args, command_count);

	if (command_path != args[0])
		free(command_path);

	return (exec_status);
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
 * @command_count: The count of commands executed so far.
 *
 * Return: The exit status of the executed command.
 */
int fork_and_execute(char *command_path, char **args, int command_count)
{
	pid_t pid;
	int status;
	int exit_status;

	pid = fork();
	if (pid == 0)
	{
		/* In child process */
		if (execve(command_path, args, environ) == -1)
		{
			print_error(args[0], errno, command_count);
			exit(errno);
		}
	}
	else if (pid < 0)
	{
		/* Fork failed */
		perror("fork failed");
		return (1);
	}
	else
	{
		/* In parent process */
		waitpid(pid, &status, 0);

		if (WIFEXITED(status))
		{
			exit_status = WEXITSTATUS(status);
		}
	}

	/* Return the exit status to the shell, but don't cause the shell to exit */
	return (exit_status);
}

