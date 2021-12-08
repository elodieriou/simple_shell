#include "simpleshell.h"

/**
 * main - program that execute a super simple shell
 * Return: 0 if success, -1 if failed
 */

int main(void)
{
	char *line = NULL, **av, *tmp;
	size_t buf = 0;
	int n, mode = 1;

	signal(SIGINT, get_signal);

	while (mode)
	{
		mode = isatty(STDIN_FILENO);
		if (mode == 1)
			_putstr("#cisfun$ ");
		n = getline(&line, &buf, stdin);
		if (n == -1)
		{
			_putchar('\n');
			free(line);
			exit(EXIT_FAILURE);
		}
		av = split(line, "' '':''\n''\t'");
		if (av[0] == NULL)
		{
			free(av);
			continue;
		}
		tmp = av[0];
		if (check_builtin(av) == -1)
		{
			get_path(av);
			if (av[0] != NULL)
				exe(av);
			if (tmp != av[0])
				free(av[0]);
		}
		else
			exe_builtins(av);
		free(av);
	}
	exit(EXIT_SUCCESS);

}
