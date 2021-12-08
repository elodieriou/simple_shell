#include "simpleshell.h"

/**
 * main - program that execute a super simple shell
 * Return: 0 if success, -1 if failed
 */

int main(void)
{
	char *line = NULL, **av, *tmp;
	size_t buf = 0;
	int n;

	signal(SIGINT, get_signal);

	while (1)
	{
		if ((isatty(STDIN_FILENO) == 1) && (isatty(STDOUT_FILENO) == 1))
			write(STDOUT_FILENO, "#cisfun$ ", 9);
		n = getline(&line, &buf, stdin);
		if (n == -1)
		{
			free(line);
			if (isatty(STDIN_FILENO) != 0)
				write(STDOUT_FILENO, "\n", 1);
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
	exit(0);
}
