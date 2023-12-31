#include "shell.h"

/**
 * handle_builtin - handles built-in commands
 * @command: command string
 * @args: array of argument strings
 *
 * Return: 1 if the command is abuilt-in command, 0 otherwise
 */

int handle_builtin(char *command, char **args)
{
	if (strcmp(command, "exit") == 0)
	{
		int status;

		if (args[1] != NULL)
			status = atoi(args[1]);
		else
			status = 0;

		free(*args);
		_exit(status);
	}
	else if (strcmp(command, "env") == 0)
	{
		print_env();
		return (1);
	}

	return (0);
}
