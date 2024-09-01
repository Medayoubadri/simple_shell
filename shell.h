#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <ctype.h>
#include <limits.h>

extern char **environ;

char *read_input(void);
char **parse_input(char *input);
int execute_command(char **args, int command_count, int *exit_status);
int handle_builtin(char **args, int *exit_status, int command_count);
char *resolve_command(char *command);
int fork_and_execute(char *command_path, char **args, int command_count);
int shell_exit(char **args, int *exit_status, int command_count);
void print_error(char *command, int error_code, int command_count);
int print_env(char **args);

char *find_in_path(char *command);
char **tokenize_input(char *input, int bufsize);
char **resize_tokens_array(char **tokens, int *bufsize);
char *custom_strtok(char *str, const char *delim);

int shell_cd(char **args);


#endif /* SHELL_H */

