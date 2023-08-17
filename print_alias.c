#include <stdio.h>
#include "shell.h"

/**
 * print_alias - Prints a single alias in the form name='value'
 * @index: the index of the alias to print
 */

void print_alias(int index)
{
	printf("%s='%s'\n", aliases[index].name,
			aliases[index].value);
}

/**
 * print_all_aliases - Prints all aliases
 */

void print_all_aliases(void)
{
	int i;

	for (i = 0; i < num_aliases; i++)
		print_alias(i);
}
