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
	int execute = 0;

	if (strcmp(args[0], "&&") == 0 && last_exit_status == 0)
		execute = 1;
	else if (strcmp(args[0], "||") == 0 && last_exit_status != 0)
		execute = 1;
	else
		execute = 1;
	if (execute)
	{
		if (!handle_builtin(command, args + (strcmp(args[0], "&&") == 0 || strcmp(args[0], "||") == 0)) &&
			!handle_setenv(args + (strcmp(args[0], "&&") == 0 || strcmp(args[0], "||") == 0)) &&
			!handle_unsetenv(args + (strcmp(args[0], "&&") == 0 || strcmp(args[0], "||") == 0)) &&
			!handle_cd(args + (strcmp(args[0], "&&") == 0 || strcmp(args[0], "||") == 0)))
		{
			execute_command(command, args + (strcmp(args[0], "&&" == 0 || strcmp(args[0], "||" = 0));
			return 0;
		}
	}

	return (last_exit_status);
}
