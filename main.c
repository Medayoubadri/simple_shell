#include "shell.h"

/**
 * main - Simple shell main loop
 *
 * Return: Always 0
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	pid_t pid;
	int status;

	while (1)
	{
		printf("($) ");  /* Display prompt */
		nread = getline(&line, &len, stdin);  /* Read user input */

		if (nread == -1)  /* Handle EOF (Ctrl+D) */
		{
			free(line);
			break;
		}

		if (line[nread - 1] == '\n')
			line[nread - 1] = '\0';

		pid = fork();  /* Create child process */
		if (pid == -1)
		{
			perror("Error");
			free(line);
			exit(EXIT_FAILURE);
		}

		if (pid == 0)
		{
			execute_command(line);
			exit(EXIT_SUCCESS);
		}
		else
		{
			wait(&status);
		}
	}

	return (0);
}

