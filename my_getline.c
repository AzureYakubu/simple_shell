#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define READ_SIZE 1024

/**
 * _getline - reads an entire line from stream
 * @lineptr: pointer to the buffer that holds the line
 * @n: size of the buffer
 * @stream: input stream
 *
 * Return: number of characters read, -1 on error or EOF
 */

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	static char buffer[READ_SIZE];
	static size_t start, end;
	ssize_t bytes_read;
	size_t i = 0;

	if (!lineptr || !n || !stream)
		return (-1);

	if (!*lineptr)
	{
		*n = READ_SIZE;
		*lineptr = malloc(*n);
		if (!*lineptr)
			return (-1);
	}

	while (1)
	{
		if (start >= end)
		{
			bytes_read = read(fileno(stream), buffer, READ_SIZE);
			if (bytes_read <= 0)
				return (bytes_read);
			start = 0;
			end = bytes_read;
		}
		while (start < end)
		{
			if (i >= *n - 1)
			{
				*n += READ_SIZE;
				*lineptr = realloc(*lineptr, *n);
				if (!*lineptr)
					return (-1);
			}
			(*lineptr)[i++] = buffer[start++];
			if ((*lineptr)[i - 1] == '\n')
			{
				(*lineptr[i] = '\0');
				 return (i);
			}
		}
	}
}
