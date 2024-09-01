#include "shell.h"

/**
 * shell_cd - Changes the current working directory.
 * @args: The arguments array.
 *
 * Return: 0 on success, 1 on error.
 */
int shell_cd(char **args)
{
	char *dir;
	char cwd[PATH_MAX];
	static char prev_dir[PATH_MAX];

	if (args[1] == NULL)
	{
		dir = getenv("HOME");
		if (dir == NULL)
			dir = "/";
	}
	else if (strcmp(args[1], "-") == 0)
	{
		if (prev_dir[0] == '\0')
		{
			fprintf(stderr, "cd: OLDPWD not set\n");
			return (1);
		}
		dir = prev_dir;
	}
	else
	{
		dir = args[1];
	}

	if (getcwd(prev_dir, sizeof(prev_dir)) == NULL)
	{
		perror("getcwd");
		return (1);
	}

	if (chdir(dir) != 0)
	{
		perror("cd");
		return (1);
	}

	setenv("OLDPWD", prev_dir, 1);
	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		setenv("PWD", cwd, 1);
	}

	return (0);
}


/**
 * shell_exit - Exits the shell.
 * @args: The arguments array (unused).
 *
 * Return: 0 to terminate the shell.
 */
int shell_exit(char **args, int *exit_status, int command_count)
{
	int i;

	if (args[1] != NULL)
	{
		for (i = 0; args[1][i] != '\0'; i++)
		{
			if (!isdigit(args[1][i]))
			{
				fprintf(stderr, "./hsh: %d: exit: Illegal number: %s\n", command_count, args[1]);
				*exit_status = 2;
				return (1);
			}
		}
		*exit_status = atoi(args[1]);
	}

	_exit(*exit_status);
}

/**
 * print_env - Prints the current environment variables.
 */
int print_env(char **args)
{
	char **env = environ;

	(void)args;

	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}

	return (1);
}

