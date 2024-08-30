#include "shell.h"

/**
 * print_error - Prints an error message.
 * @command: The command that caused the error.
 * @error_code: The error code (e.g., ENOENT for file not found).
 * @command_count: Count the commands DUH!!
 */
void print_error(char *command, int error_code, int command_count)
{
	if (error_code == ENOENT)
	{
		fprintf(stderr, "./hsh: %d: %s: not found\n", command_count, command);
	}
	else if (error_code == EACCES)
	{
		fprintf(stderr, "./hsh: %d: %s: Permission denied\n",
				command_count, command);
	}
	else
	{
		fprintf(stderr, "./hsh: %d: %s: An unknown error occurred\n",
				command_count, command);
	}
}
