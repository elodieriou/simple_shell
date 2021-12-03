#include "simpleshell.h"

/**
 * main - program that execute a super simple shell
 * Return: 0 if success, -1 if failed
 */

int main(void)
{
	char *line = NULL, **av;
	size_t buf = 0;
	int n;
	struct stat st;

	while (1)
	{
		_putstr("#cisfun$ ");
		n = getline(&line, &buf, stdin);
		if (n == -1)
		{
			free(line);
			exit(EXIT_FAILURE);
		}
		if (line[0] == '\n')
			continue;
		av = split(line, "' '':''\n''\t'");
		if (stat(av[0], &st) == 0)
			exe(av);
		else
			perror("./hsh");
		free(av);
	}
	exit(EXIT_SUCCESS);
}
