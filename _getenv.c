#include "main.h"

/**
 * _getenv - gets an environment variable. (without using getenv)
 * Return: string or 0 if failed
 */

char *_getenv(const char *name)
{
	int i;
	char *token;
	extern char **environ;

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
