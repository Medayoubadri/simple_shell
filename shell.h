#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

char *read_input(void);
char **parse_input(char *input);
int execute_command(char **args);
int handle_builtin(char **args);
char *resolve_command(char *command);
void fork_and_execute(char *command_path, char **args);
int shell_exit(char **args);
void print_error(char *command, int error_code);
char *find_in_path(char *command);

#endif /* SHELL_H */

