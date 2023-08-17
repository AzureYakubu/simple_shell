#include "shell.h"

/**
 * handle_variable_replacement - ...
 * @args: ...
 * @last_exit_status: ...
 */

void handle_variable_replacement(char **args, int last_exit_status)
{
	int i;

	for (i = 0; args[i]; i++)
	{
		if (strcmp(args[i], "$?") == 0)
		{
			free(args[i]);
			args[i] = malloc(4);
			sprintf(args[i], "%d", last_exit_status);
		}
		else if (strcmp(args[i], "$$") == 0)
		{
			free(args[i]);
			args[i] = malloc(16);
			sprintf(args[i], "%d", getpid());
		}
	}
}
