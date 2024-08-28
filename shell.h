#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

/* Global variables */
extern char **environ;

void execute_command(char *command);
void handle_error(char *command);
char *find_command_path(char *command);
void handle_exit(char *command);
void handle_env(char *command);
void process_command(char *line);
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream);

#endif /* SHELL_H */

