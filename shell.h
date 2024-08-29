#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

/*
 * ==========================
 *    Globale Variables
 * ==========================
 */
extern char **environ;

/*
 * ==========================
 *        Built-ins
 * ==========================
 */

/* Handles the exit built-in command */
void handle_exit(char *command);

/* Prints the current environment variables */
void handle_env(char *command);

/* Initializes or modifies an environment variable */
void handle_setenv(char *command);

/* Removes an environment variable */
void handle_unsetenv(char *command);

/* Handles the echo built-in command */
void handle_echo(char *command);


/*
 * ==========================
 *     Command Execution
 * ==========================
 */

/* Executes a command using execve */
void execute_command(char *command);

/* Forks and executes a command using execve */
void run_command(char *cmd_path, char **argv);

/* Prints an error message when a command cannot be executed */
void handle_error(char *command);

/* Finds the command in the PATH and returns its full path */
char *find_command_path(char *command);

/* Processes the user's command input */
void process_command(char *line);


/*
 * ===========================
 *      Tokenization
 * ===========================
 */

/* Counts the number of tokens in a string */
int count_the_mess(char *str, const char *delim);

/* Splits a command string into tokens */
char **tokey_slicer(char *command, const char *delim);


/*
 * ===========================
 *       Input Handling
 * ===========================
 */

/* Custom implementation of getline function */
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream);


/*
 * ============================
 *       Memory Management
 * ============================
 */
/* Frees a pointer and sets it to NULL */
void free_and_nullify(char **ptr);

/* Frees an array of pointers */
void free_pointer_array(char **array);

/* Safely reallocates memory, freeing original on failure */
void *safe_realloc(void *ptr, size_t new_size);

/* Frees the memory allocated for tokens */
void free_tokens(char **tokens);

#endif /* SHELL_H */

