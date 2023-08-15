#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "shell.h"
/**
 * get_command - search for an excutable file
 *
 * return
 */ 

char *get_command(char *line, char *path)
{
	char *path_copy = strdup(path);
	char *dir;
	char buffer[1024];
	char *command = NULL;

	for (dir = strtok(path_copy, ":"); dir != NULL; dir = strtok(NULL, ":"))
	{
		snprintf(buffer, sizeof(buffer), "%s%s", dir, line);
		if (access(buffer, X_OK) == 0)
		{
			command = strdup(buffer);
			break;
		}
	}
	
	free(path_copy);

	return command;
}
