#include "shell.h"

#define MAX_ARGS 128
#define MAX_COMMANDS 128

/**
 * handle_logical_operators - handle logical operators
 *
 * @command: ...
 * @args: ...
 * @last_exit_status: ...
 * Return: ...
 */

int handle_logical_operators(char *command, char **args, int last_exit_status)
{
	if (strcmp(args[0], "&&") == 0)
	{
		if (last_exit_status == 0)
		{
			if (!handle_builtin(command, args + 1) &&
				!handle_setenv(args + 1) &&
				!handle_unsetenv(args + 1) &&
				!handle_cd(args + 1))
			return (execute_command(command, args + 1));
		}
	}
	else if (strcmp(args[0], "||" == 0)
	{
		if (last_exit_status != 0)
		{
			if (!handle_builtin(command, args + 1) &&
				!handle_setenv(args + 1) &&
				!handle_unsetenv(args + 1) &&
				!handle_cd(args + 1))
			return (execute_command(command, args + 1));
		}
	}
	else
	{
		if (!handle_builtin(command, args) &&
			!handle_setenv(args) &&
			!handle_unsetenv(args) &&
			!handle_cd(args))
		return (execute_command(command, args));
	}

	return (last_exit_status);
}
