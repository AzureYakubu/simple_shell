#include <stdlib.h>
#include <string.h>
#include "shell.h"

/**
 * handle_unsetenv - handles the unsetenv built-in command
 * @args: array of arguments strings
 *
 * Return: 1 if command is built-in, 0 otherwise
 */

int handle_unsetenv(char **args)
{
	if (strcmp(args[0], "unsetenv" == 0)
	{
		if (args[1] == NULL)
		{
			fprintf(stderr, "unsetenv: missing argument\n");
			return (1);
		}

		if (unsetenv(args[1]) == -1)
			perror("unsetenv");
		return (1);
	}

	return (0);
}
