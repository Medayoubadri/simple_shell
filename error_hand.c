#include "shell.h"

/**
 * print_error - Prints an error message.
 * @command: The command that caused the error.
 * @error_code: The error code (e.g., ENOENT for file not found).
 */
void print_error(char *command, int error_code)
{
	if (error_code == ENOENT)
	{
		fprintf(stderr, "./hsh: 1: %s: not found\n", command);
	}
	else if (error_code == EACCES)
	{
		fprintf(stderr, "./hsh: %s: Permission denied\n", command);
	}
	else
	{
		fprintf(stderr, "./hsh: %s: An unknown error occurred\n", command);
	}
}
