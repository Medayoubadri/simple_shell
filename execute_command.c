#include "shell.h"

/**
 * run_command - Forks and executes a command using execve
 * @cmd_path: The path to the command
 * @argv: The argument array for the command
 */
void run_command(char *cmd_path, char **argv)
{
	if (fork() == 0)  /* Child process */
	{
		if (execve(cmd_path, argv, NULL) == -1)
			handle_error(argv[0]);
		exit(EXIT_FAILURE);
	}
	else  /* Parent process */
	{
		wait(NULL);  /* Wait for the child to finish */
	}
}

/**
 * free_tokens - Frees the memory allocated for tokens
 * @tokens: The array of tokens to free
 */
void free_tokens(char **tokens)
{
	int i;

	for (i = 0; tokens[i]; i++)
		free(tokens[i]);
	free(tokens);
}

/**
 * execute_command - Executes a command using execve
 * @command: The command to execute
 *
 * Description: This function is on a mission to execute your command.
 * If it fails, the shell will self-destruct (JK, it’ll just print an error).
 */
void execute_command(char *command)
{
	char **argv;
	char *cmd_path;

	/* Tokenize the command string into arguments */
	argv = tokey_slicer(command, " ");
	if (!argv || !argv[0])
	{
		if (argv)
			free_tokens(argv);
		return;
	}

	/* Check if the command is a full path */
	cmd_path = (command[0] == '/') ? command : find_command_path(argv[0]);

	if (!cmd_path)
	{
		handle_error(argv[0]);
		free_tokens(argv);
		return;
	}

	/* Execute the command */
	run_command(cmd_path, argv);

	/* Free allocated memory for tokens */
	free_tokens(argv);
}

