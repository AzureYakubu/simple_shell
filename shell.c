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

	while ((ncmds = read_input(&line, &len, commands)) != -1)
	{
		for (int i = 0; i < ncmds; i++)
		{
			command = commands[i];

			if (strcmp(args[0], "alias") == 0)
				handle_alias(args);
			else
			{
				split_string(command, " ", args);
				handle_comments(args);
				handle_variable_replacement(args,
					last_exit_status);
				last_exit_status = handle_logical_operators
					(command, args, last_exit_status);
			}
		}
	}
	free(line);
	if (fp != stdin)
		fclose(fp);
	return (0);
}
