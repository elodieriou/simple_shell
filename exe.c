#include "simpleshell.h"

/**
 * exe - function that execute a commande
 * @av: an array of string that contain the command
 * Return: void
 */

int exe(char **av)
{
	pid_t child_pid;
	int status, exe;

	child_pid = fork();
	if (child_pid == -1)
		perror("fork");
	else if (child_pid > 0)
	{
		waitpid(child_pid, &status, 0);
		kill(child_pid, SIGTERM);
	}
	else
	{
		exe = execve(av[0], av, environ);
		if (exe == -1)
		{
			perror(av[0]);
			exit(0);
		}
	}
	return (0);
}
