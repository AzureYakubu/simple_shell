#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "shell.h"

/**
 * handle_alias - ...
 * @args: ...
 */

void handle_alias(char **args)
{
	int i;
	char *arg;
	char *equal_sign;

	if (args[1] == NULL)
	{
		print_all_aliases();
		return;
	}

	for (i = 1; args[i] != NULL; i++)
	{
		arg = args[i];

		equal_sign = strchr(arg, '=');

		if (equal_sign != NULL)
		{
			*equal_sign = '\0';
			add_alias(arg, equal_sign + 1);
		}
		else
		{
			int index = find_alias(arg);

			if (index >= 0)
				print_alias(index);
			else
				printf("alias: %s: not found\n", arg);
		}
	}
}
