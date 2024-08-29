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
int shell_exit(char **args);
void print_error(char *command, int error_code);

#endif /* SHELL_H */

