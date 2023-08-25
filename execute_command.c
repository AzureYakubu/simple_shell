#include "shell.h"

/**
 * execute_command - executes an external command
 * @command: command string
 * @args: array of argument strings
 */

void execute_command(char *command, char **args)
{
	pid_t child_pid;
	int status;
	char *path;

	path = get_path();
	if (path == NULL)
		fprintf(stderr, "Error: PATH not set\n");

	command = get_command(command);

	if (command == NULL)
	{
		fprintf(stderr, "Error: command not found; %s\n", args[0]);
		exit(EXIT_FAILURE);
	}

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
	}
	else
	{
		if (child_pid == 0)
		{
			if (execve(args[0], args, NULL) == -1)
			{
				perror("Error:");
			}
		}
		else
		{
			wait(&status);
		}
	}

}
