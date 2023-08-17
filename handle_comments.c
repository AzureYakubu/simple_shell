#include "shell.h"

/**
 * handle_comments - ...
 * @args: ...
 *
 */

void handle_comments(char **args)
{
	int i, j;

	for (i = 0; args[i]; i++)
	{
		if (args[i][0] == '#')
		{
			for (j = i; args[j]; j++)
			{
				free(args[j]);
				args[j] = NULL;
			}
			break;
		}
	}
}
