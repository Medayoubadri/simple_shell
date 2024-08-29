#include "shell.h"

/**
 * print_error - Prints an error message.
 * @command: The command that caused the error.
 * @error_code: The error code (e.g., ENOENT for file not found).
 */
void print_error(char *command, int error_code)
{
	char *error_msg;

	if (error_code == ENOENT)
		error_msg = "No such file or directory";
	else if (error_code == EACCES)
		error_msg = "Permission denied";
	else
		error_msg = "An unknown error occurred";

	fprintf(stderr, "./hsh: %s: %s\n", command, error_msg);
}

