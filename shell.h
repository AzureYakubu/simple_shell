#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ALIAS 128

char *get_path(void);
char *get_command(char *line, char *path);
void handle_exit(void);
void print_env(void);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
ssize_t read_input(char **lineptr, size_t *n, char **command);
int handle_builtin(char *command, char **args);
void execute_command(char *command, char **args);
int handle_setenv(char **args);
int handle_unsetenv(char **args);
int handle_cd(char **args);
int handle_logical_operators(char *command, char **args, int last_exit_status);
typedef struct alias
{
	char *name;
	char *value;
}
alias_t;

extern alias_t aliases[MAX_ALIAS];
extern int num_aliases;
extern char **environ;

void handle_alias(char **args);
int find_alias(char *name);
void print_alias(int index);
void print_all_aliases(void);
void add_alias(char *name, char *value);
void handle_variable_replacement(char **args, int last_exit_status);
void handle_comments(char **args);
int split_string(char *str, const char *delim, char **tokens);

#endif /* SHELL_H */
