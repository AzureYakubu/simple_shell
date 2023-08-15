#include "shell.h"

#define MAX_ARGS 128

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
		if (nargs == -1)
			break;
		for (int i = 0; i < ncmds; i++)
		{
			command = commands[i];
			split_string(command, " ", args);

			if (!handle_builtin(command, args) &&
				!handle_setenv(args) &&
				!handle_unsetenv(args) &&
				!handle_cd(args))
				execute_command(command, args);
		}
	}

	free(line);
	return (0);
}
