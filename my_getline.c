#include "shell.h"

static char buffer[1024];
static size_t buffer_pos;
static size_t buffer_size;

/**
 * refill_buffer - Refills the buffer with data from the input stream
 * @stream: The input stream to read from
 *
 * Return: The number of bytes read, or -1 on error
 */
ssize_t refill_buffer(FILE *stream)
{
	buffer_size = read(fileno(stream), buffer, sizeof(buffer));
	buffer_pos = 0;
	return (buffer_size);
}

/**
 * assign_lineptr - Assigns the content of the buffer to lineptr
 * @lineptr: Pointer to the buffer to store the input line
 * @n: Size of the buffer
 * @buffer: The source buffer
 * @len: Length of the buffer content to be assigned
 *
 * Description: Ensures that the buffer is properly resized and assigned
 */
void assign_lineptr(char **lineptr, size_t *n, char *buffer, size_t len)
{
	if (*lineptr == NULL || *n < len)
	{
		if (len > 120)
			*n = len;
		else
			*n = 120;
		*lineptr = realloc(*lineptr, *n);
	}
	strncpy(*lineptr, buffer, len);
	(*lineptr)[len] = '\0';
}
/**
 * my_getline - Custom implementation of getline function
 * @lineptr: Pointer to the buffer where the line will be stored
 * @n: Pointer to the size of the buffer
 * @stream: The input stream to read from
 *
 * Description: apparently calling "read" every time you need a character
 *              is 'inefficient.' So here’s a buffer-filled solution
 *              to keep the critics quiet.
 *
 * Return: The number of characters read, or -1 on failure or EOF.
 */
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
	ssize_t total_read = 0;
	char c = 'x';

	if (!lineptr || !n || !stream)
		return (-1);

	if (*lineptr == NULL || *n == 0)
	{
		*n = 128;
		*lineptr = malloc(*n);
		if (*lineptr == NULL)
			return (-1);
	}

	while (1)
	{
		if (buffer_pos >= buffer_size)
		{
			if (refill_buffer(stream) <= 0)
				return (total_read > 0 ? total_read : -1);
		}

		while (buffer_pos < buffer_size)
		{
			c = buffer[buffer_pos++];
			(*lineptr)[total_read++] = c;

			if (c == '\n')
			{
				assign_lineptr(lineptr, n, *lineptr, total_read);
				return (total_read);
			}
		}
	}
}

