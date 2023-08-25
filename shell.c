#include "shell.h"
#define MAX_ARGS 128
#define MAX_COMMANDS 128

/**
 * main - Entry point
 *
 * @argc: ...
 * @argv: ...
 * Return: Always (0)
 */

int main(int argc, char **argv)
{
	char *line = NULL, *command, *args[MAX_ARGS];
	size_t len = 0;
	ssize_t ncmds;
	char *commands[MAX_COMMANDS];
	int last_exit_status = 0;
	FILE *fp = (argc > 1) ? fopen(argv[1], "r") : stdin;
	int i;

	for (i = 0; i < MAX_ARGS; i++)
	{
		args[i] = NULL;
	}
	
	while ((ncmds = read_input(&line, &len, commands)) != -1)
	{
		for (i = 0; i < ncmds; i++)
		{
			if (strcmp(commands[i], "alias") == 0)
				handle_alias(args);
			else
			{
				handle_comments(args);
				handle_variable_replacement(args,
					last_exit_status);
				last_exit_status = handle_logical_operators
					(args[0], args, last_exit_status);
			}
		}
	}
	free(line);
	if (fp != stdin)
		fclose(fp);
	return (0);
}
