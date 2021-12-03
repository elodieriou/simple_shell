#include "simpleshell.h"

/**
 * _getenv - gets an environment variable. (without using getenv)
 * @name: name of the value (var)
 * Return: string or 0 if failed
 */

char *_getenv(const char *name)
{
	int i;
	char *token;

	for (i = 0; environ[i] != NULL; i++)
	{
		token = strtok(environ[i], "=");
		if (strcmp(token, name) == 0)
		{
			token = strtok(NULL, "=");
			return (token);
		}
	}
	return (0);
}
