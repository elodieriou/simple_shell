#include "simpleshell.h"

/**
 * get_path - get the absolute path of
 * @av: array of strings (arguments of getline)
 * Return: a string
 */

void get_path(char **av)
{
	char *path = NULL, *token = NULL, *bin = NULL;
	struct stat st;
	int i;

	path = _strdup(_getenv("PATH"));
	bin = malloc(sizeof(char *));
	if (bin == NULL)
		perror("malloc");
	token = strtok(path, ":");

	for (i = 0; token != NULL; i++)
	{
		/* concatenate (ex ls -> /bin/ls))*/
		bin = _realloc(bin, sizeof(bin),
			       sizeof(bin) * (_strlen(token) * (i + 2) * sizeof(char *)));
		if (bin == NULL)
			perror("realloc");
		bin = _strcat(bin, token);
		bin = _strcat(bin, "/");
		bin = _strcat(bin, av[0]);
		printf("token: %s\n", token);
		printf("bin: %s\n", bin);
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
