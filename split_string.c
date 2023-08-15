#include <string.h>
#include <stdlib.h>

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
	int i;

	token = str;
	i = 0;
	while (*str != '\0' && i < MAX_TOKENS - 1)
	{
		if (strchr(delim, *str) != NULL)
		{
			*str = '\0;
			if (*token != '\0')
				tokens[i++] = token;
			token = str + 1;
		}
		str++;
	}
	if (*token != '\0')
		tokens[i++] = token;
	tokens[i] = NULL;
	return (i);
}
