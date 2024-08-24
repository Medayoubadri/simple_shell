#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

void execute_command(char *command);
void handle_error(char *command);
char *find_command_path(char *command);
void handle_exit(char *command);

#endif /* SHELL_H */

