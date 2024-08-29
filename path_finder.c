#include "shell.h"

/**
 * find_in_path - Searches for a command in the directories listed in PATH.
 * @command: The command to find.
 *
 * Return: The full path of the command if found, NULL if not found.
 */
char *find_in_path(char *command)
{
	char *path = getenv("PATH");
	char *path_copy, *token, *full_path;
	size_t length;

	if (!path || !command)
		return (NULL);

	path_copy = strdup(path);
	if (!path_copy)
		return (NULL);

	token = strtok(path_copy, ":");
	while (token)
	{
		length = strlen(token) + strlen(command) + 2;
		full_path = malloc(length);
		if (!full_path)
		{
			free(path_copy);
			return (NULL);
		}

		snprintf(full_path, length, "%s/%s", token, command);
		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}
		free(full_path);
		token = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}

