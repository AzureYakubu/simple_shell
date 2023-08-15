#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

char *get_path(void);
char *get_command(char*line, char *path);
void handle_exit(void);
void print_env(void);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
ssize_t read_input(char **lineptr, size_t *n, char **command, char **args);
int handle_builtin(char *command, char **args);
void execute_command(char *command, char **args);
int handle_setenv(char **args);
int handle_unsetenv(char **args);
int handle_cd(char **args);

#endif /* SHELL_H */
