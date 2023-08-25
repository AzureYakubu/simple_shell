#include <stdlib.h>
#include <string.h>
#include "shell.h"

/**
 * handle_setenv - handles the setenv built-in command
 * @args: array of argument strings
 *
 * Return: 1 if the command is a built-in, 0 otherwise
 */

int handle_setenv(char **args)
{
	if (strcmp(args[0], "setenv") == 0)
	{
		if (args[1] == NULL || args[2] == NULL)
		{
			fprintf(stderr, "setenv: missing argument\n");
			return (1);
		}

		if (setenv(args[1], args[2], 1) == -1)
		{
			perror("setenv");
			exit(EXIT_FAILURE);
		}
		return (1);
	}

	return (0);
}
