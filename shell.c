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
	ssize_t nargs;
	char *command;
	char *args[MAX_ARGS];

	while (1)
	{
		nargs = read_input(&line, &len, &command, args);
		if (nargs == -1)
			break;

		if (!handle_builtin(command, args) &&
			!handle_setenv(args) &&
			!handle_unsetenv(args))
			execute_command(command, args);
	}

	free(line);
	return (0);
}
