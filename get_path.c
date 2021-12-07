#include "simpleshell.h"

/**
 * get_path - get the absolute path
 * @av: array of strings (arguments of getline)
 * Return: a string
 */

void get_path(char **av)
{
	char *path = NULL, *token = NULL, *bin = NULL;
	struct stat st;
	int i;

	path = _strdup(_getenv("PATH"));
	token = strtok(path, ":");

	for (i = 0; token != NULL; i++)
	{
		/* concatenate (ex ls -> /bin/ls))*/
		bin = _realloc(bin, sizeof(bin),
		       ((_strlen(token) + _strlen(av[0]) + 2) * sizeof(char)));
		if (bin == NULL)
		{
			free(bin);
			return;
		}

		bin = _strcat(bin, token);
		bin = _strcat(bin, "/");
		bin = _strcat(bin, av[0]);
		if (stat(bin, &st) == 0)
		{
			av[0] = bin;
			free(path);
			return;
		}
		token = strtok(NULL, ":");
		bin = NULL;
	}
}


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
