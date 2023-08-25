#include "shell.h"

#define MAX_ARGS 128
#define MAX_COMMANDS 128

/**
 * read_input - reads a line from the standard input stream
 * and parses it into a command and arguments
 * @lineptr: pointer to the buffer that holds the line
 * @n: size of the buffer
 * @command: pointer to the command string
 *
 * Return: number of commands, -1 on error or EOF
 */

ssize_t read_input(char **lineptr, size_t *n, char **command)
{
	ssize_t read;
	int ncmds;
	char *commands[MAX_COMMANDS];
	int i;

	printf("$ ");
	read = _getline(lineptr, n, stdin);
	if (read == -1)
		return (-1);

	(*lineptr)[read - 1] = '\0';

	ncmds = split_string(*lineptr, ";", commands);
	for (i = 0; i < ncmds; i++)
	{
		command[i] = commands[i];
		while (*command[i] == ' ')
			command[i]++;
		commands[i] = command[i];
	}

	return (ncmds);
}
