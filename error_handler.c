#include "shell.h"

/**
 * handle_error - Prints an error message
 * @command: The command that caused the error
 */
void handle_error(char *command)
{
	fprintf(stderr, "%s: command not found\n", command);
}

