#include "shell.h"

/**
 * get_path - gets the PATH environment variable
 *
 * Return: pointer to the Path environement variable, NULL or failure
 */
char *get_path(void)
{
	char *path;

	path = getenv("PATH");
	if (path == NULL)
	{
		fprintf(stderr, "Error: Path not set\n");
		exit(EXIT_FAILURE);
	}

	return (path);
}
