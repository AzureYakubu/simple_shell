#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "shell.h"

/**
 * get_command - search for an excutable file
 *
 * @line: the input line
 * @path: ...
 *
 * Returns: duplicate string of the input line
 */

char *get_command(char *line)
{
	return (strdup(line));
}
