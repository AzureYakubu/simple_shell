#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * main - Entry point
 *
 * Return: Always (0)
 */

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	pid_t child_pid;
	int status;

	while (1)
	{
		printf("$ ");
		read = getline(&line, &len, stdin);
		if (read == -1)
			break;
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}
		if (child_pid == 0)
		{
			char *args[] = {NULL, NULL};

			args[0] = line;

			if (execve(args[0], args, NULL) == -1)
			{
				perror("Error:");
				return (1);
			}
		}
		else
			wait(&status);
	}
	free(line);
	return (0);
}
