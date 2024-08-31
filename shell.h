#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

extern char **environ;

char *read_input(void);
char **parse_input(char *input);
int execute_command(char **args, int command_count);
int handle_builtin(char **args);
char *resolve_command(char *command);
int fork_and_execute(char *command_path, char **args, int command_count);
int shell_exit(char **args);
void print_error(char *command, int error_code, int command_count);
int print_env(char **args);

char *find_in_path(char *command);
ssize_t getline_custom(char **lineptr, size_t *n, FILE *stream);
char **tokenize_input(char *input, int bufsize);
char **resize_tokens_array(char **tokens, int *bufsize);

#endif /* SHELL_H */

