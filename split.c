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

	av = malloc(sizeof(char *));
	if (av == NULL)
		exit(EXIT_FAILURE);
	token = strtok(line, delim);
	for (i = 0; token != NULL; i++)
	{
		av[i] = token;
		token = strtok(NULL, delim);
		av = _realloc(av, sizeof(av) * (i + 1),
			      (sizeof(av) * (i + 1)) + sizeof(char *));
	}

	av[i] = token;
	return (av);
}
