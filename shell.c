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

	while (1)
	{
		_putstr("#cisfun$ ");
		n = getline(&line, &buf, stdin);
		if (n == -1)
		{
			free(line);
			exit(EXIT_FAILURE);
		}
		av = split(line, " \n\t");
		if (line == NULL)
			perror(av[0]);
		else
			exe(av);
		free(av);
	}
	free(line);
}
