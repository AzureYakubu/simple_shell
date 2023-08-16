#include "shell.h"

#define MAX_ARGS 128
#define MAX_COMMANDS 128

/**
 * main - Entry point
 *
 * Return: Always (0)
 */

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t ncmds;
	char *commands[MAX_COMMANDS];
	char *command;
	char *args[MAX_ARGS];

	while (1)
	{
		ncmds = read_input(&line, &len, commands);
		if (ncmds == -1)
			break;
		for (int i = 0; i < ncmds; i++)
		{
			command = commands[i];
			split_string(command, " ", args);
			last_exit_status = handle_logical_operators
				(command, args, last_exit_status);
		}
	}

	free(line);
	return (0);
}
