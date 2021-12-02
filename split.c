#include "simpleshell.h"

/**
 * split - funtion that parse a string
 * @line: a string of charater stdin
 * @delim: a delimitor
 * Return: an array of string
 */

char **split(char *line, char *delim)
{
	char *token, **av;
	int i = 0;

/* Extract token from a string line */
	token = strtok(line, delim);
	for (i = 0; token != NULL; i++)
	{
	/* Realloc memory for each token */
	/* Add token to an array */
	/* Change token */
		av = _realloc(av, sizeof(av) * (i + 1),
			      (sizeof(av) * (i + 1)) + sizeof(char *));
		av[i] = token;
		token = strtok(NULL, delim);
	}
/* Realloc memory for a token that take NULL value at the end of array */
	av = _realloc(av, sizeof(av) * (i + 1),
		      (sizeof(av) * (i + 1)) + sizeof(char *));
	av[i] = NULL;
	return (av);
}
