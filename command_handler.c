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
	handle_exit(line);
	handle_env(line);
	execute_command(line);
}

