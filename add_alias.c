#include <string.h>
#include <stdlib.h>
#include "shell.h"

/**
 * add_alias - ...
 * @name: ...
 * @value: ...
 */

void add_alias(char *name, char *value)
{
	int index = find_alias(name);

	if (index >= 0)
	{
		free(aliases[index].value);
		aliases[index].value = strdup(value);
	}
	else
	{
		aliases[num_aliases].name = strdup(name);
		aliases[num_aliases].value = strdup(value);
		num_aliases++;
	}
}
