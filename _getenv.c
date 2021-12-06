#include "simpleshell.h"

/**
 * _getenv - gets an environment variable. (without using getenv)
 * @name: name of the value (var)
 * Return: string or 0 if failed
 */

char *_getenv(const char *name)
{
	char *token, **tmp;
	int i;

	tmp = malloc(sizeof(char *));
	for (i = 0; environ[i] != NULL; i++)
	{
		tmp[i] = _realloc(tmp, sizeof(tmp),
				  (_strlen(environ[i]) * sizeof(char) + 1));
		tmp[i] = _strdup(environ[i]);
	}
	for (i = 0; tmp[i] != NULL; i++)
	{
		token = strtok(tmp[i], "=");
		if (_strcmp(token, name) == 0)
		{
			token = strtok(NULL, "=");
			free(tmp);
			return (token);
		}
	}
	free(tmp);
	return (0);
}
