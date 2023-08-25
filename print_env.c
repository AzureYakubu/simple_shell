#include <stdio.h>
#include <unistd.h>
#include "shell.h"

/**
 * print_env - print environment varaible
 *
 */

void print_env(void)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		printf("%s\n", environ[i]);
	}
}
