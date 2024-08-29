#include "shell.h"

/**
 * process_command - Processes the user input and handles built-ins
 * @line: The user input line
 *
 * Description: This function handles the exit and env built-in commands,
 * before delegating any other command to the execution function.
 */
void process_command(char *line)
{
	if (line[0] == '\0')
		return;

	/* Check for the exact "exit" command */
	if (strncmp(line, "exit", 4) == 0 && (line[4] == ' ' || line[4] == '\0'))
	{
		handle_exit(line);
		return;
	}

	if (strncmp(line, "echo", 4) == 0 && (line[4] == ' ' || line[4] == '\0'))
	{
		handle_echo(line);
		return;
	}

	handle_env(line);

	/* Check for setenv and unsetenv commands */
	if (strncmp(line, "setenv", 6) == 0 && (line[6] == ' ' || line[6] == '\0'))
	{
		handle_setenv(line);
		return;
	}
	if (strncmp(line, "unsetenv", 8) == 0 && (line[8] == ' ' || line[8] == '\0'))
	{
		handle_unsetenv(line);
		return;
	}

	execute_command(line);
}

