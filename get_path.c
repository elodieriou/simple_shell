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

	path = _strdup(_getenv());
	token = strtok(path, ":");

	for (i = 0; token != NULL; i++)
	{
		/* concatenate (ex ls -> /bin/ls))*/
		bin = _realloc(bin, sizeof(bin),
		  (_strlen(av[0]) + _strlen(token)) * sizeof(char) * 3);
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
		free(bin);
		bin = NULL;
	}
}

/**
 * _getenv - gets an environment variable. (without using getenv)
 * Return: string or 0 if failed
 */

char *_getenv(void)
{
	int x;
	char **env = environ, *path = NULL;

	while (*env)
	{
		if (_strncmp(*env, "PATH=", 5) == 0)
		{
			path = *env;
			while (*path && x < 5)
			{
				path++;
				x++;
			}
			return (path);
		}
		env++;
	}
	return (NULL);
}
