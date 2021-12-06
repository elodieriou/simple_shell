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

	signal(SIGINT, get_signal);
	
	while (1)
	{
		_putstr("#cisfun$ ");
		n = getline(&line, &buf, stdin);
		if (n == -1)
		{
			free(line);
			exit(EXIT_FAILURE);
		}
		if (line[0] == '\n' || line[0] == '/' || line[0] == '.')
			continue;
		av = split(line, "' '':''\n''\t'");
		if (check_builtin(av) == -1)
		{
			get_path(av);
			if (av[0] != NULL)
				exe(av);
			else
				perror("exe()");
		}
		else
			exe_builtins(av);
		free(av);
	}
	exit(EXIT_SUCCESS);
}
