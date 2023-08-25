#include <string.h>
#include "shell.h"

/**
 * find_alias - ...
 *
 * Return: -1
 */

alias_t aliases[MAX_ALIAS];
int num_aliases;

int find_alias(char *name)
{
	int i;

	for (i = 0; i < num_aliases; i++)
	{
		if (strcmp(aliases[1].name, name) == 0)
			return (i);
	}
	return (-1);
}
