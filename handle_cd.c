#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

/**
 * handle_cd - handles the cd built-in command
 * @args: array of argument strings
 *
 * Return: 1 if the command is a built-in, 0 otherwise
 */

int handle_cd(char **args)
{
	char *path;
	char cwd[4096];

	if (strcmp(args[0], "cd") == 0)
	{
		if (args[1] != NULL)
			path = args[1];
		else
			path = getenv("HOME");

		if (chdir(path) == -1)
			perror("cd");

		if (getcwd(cwd, sizeof(cwd)) != NULL)
			setenv("PWD", cwd, 1);

		return (1);
	}

	return (0);
}
