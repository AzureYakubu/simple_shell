#include "shell.h"

#define MAX_ARGS 128

/**
 * read_input - reads a line from the standard input stream
 * and parses it into a command and arguments
 * @lineptr: pointer to the buffer that holds the line
 * @n: size of the buffer
 * @command: pointer to the command string
 * @args: array of argument strings
 *
 * Return: number of arguments, -1 on error or EOF
 */

ssize_t read_input(char **lineptr, size_t *n, char **command, char **args)
{
	ssize_t read;
	int nargs;

	printf("$ ");
	read = _getline(lineptr, n, stdin);
	if (read == -1)
		return (-1);

	(*lineptr)[read - 1] = '\0';

	nargs = split_string(*lineptr, " ", args);
	if (nargs > 0)
		*command = args[0];
	else
		*command = NULL;

	return (nargs);
}
