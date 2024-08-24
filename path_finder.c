#include "shell.h"

/**
 * find_command_path - Searches for the command in the directories in PATH
 * @command: The command to find
 *
 * Return: The full path to the command if found, otherwise NULL
 */
char *find_command_path(char *command)
{
	char *path_env = getenv("PATH");
	char *path, *dir;
	static char full_path[1024];

	if (!path_env)
		return (NULL);

	/* Duplicate PATH to avoid modifying the original environment variable */
	path = strdup(path_env);
	if (!path)
		return (NULL);

	/* Split PATH into directories */
	dir = strtok(path, ":");
	while (dir != NULL)
	{
		snprintf(full_path, sizeof(full_path), "%s/%s", dir, command);
		if (access(full_path, X_OK) == 0)
		{
			free(path);
			return (full_path);
		}
		dir = strtok(NULL, ":");
	}
	free(path);
	return (NULL);
}

