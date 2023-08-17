#include <string.h>
#include <stdlib.h>
#include "shell.h"

#define MAX_TOKENS 128

/**
 * split_string - splits a string into tokens based on a delimiter
 * @str: the string to split
 * @delim: the delimiter
 * @tokens: an array of character pointers to store the tokens
 *
 * Return: the number of tokens
 */
int split_string(char *str, const char *delim, char **tokens)
{
	char *token;
	int i = 0;

	token = strtok(str, delim);
	while (token != NULL && i < MAX_TOKENS)
	{
		tokens[i++] = token;
		token = strtok(NULL, delim);
	}
	return (i);
}
