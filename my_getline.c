#include "shell.h"
#include <stdlib.h>
#include <unistd.h>

#define INITIAL_BUFFER_SIZE 1024

/**
 * getline_custom - Custom implementation of getline function
 * @lineptr: Pointer to the buffer where the line will be stored
 * @n: Pointer to the size of the buffer
 * @stream: The input stream to read from
 *
 * Return: The number of characters read, or -1 on failure or EOF.
 */
ssize_t getline_custom(char **lineptr, size_t *n, FILE *stream)
{
	size_t buffer_size = INITIAL_BUFFER_SIZE;
	size_t total_read = 0;
	ssize_t bytes_read;
	char *buffer;
	char c;

	if (!lineptr || !n || !stream)
		return (-1);

	buffer = malloc(buffer_size);
	if (!buffer)
		return (-1);

	while ((bytes_read = read(fileno(stream), &c, 1)) > 0)
	{
		if (total_read + 1 >= buffer_size)
		{
			buffer_size *= 2;
			buffer = realloc(buffer, buffer_size);
			if (!buffer)
				return (-1);
		}
		buffer[total_read++] = c;
		if (c == '\n')
			break;
	}

	if (bytes_read == -1 || (bytes_read == 0 && total_read == 0))
	{
		free(buffer);
		return (-1);
	}

	if (bytes_read == 0 && total_read == 0)
	{
		free(buffer);
		return (-1);
	}

	buffer[total_read] = '\0';
	*lineptr = buffer;
	*n = buffer_size;

	return (total_read);
}

