#include "simpleshell.h"

/**
 * exe - function that execute a commande
 * @av: an array of string that contain the command
 * Return: void
 */

void exe(char **av)
{
	pid_t child_pid;
	int status, exe;

/* Action fork to create a child process */
	child_pid = fork();
	if (child_pid == -1)
		perror("fork");
/* If fork is a success, the ppid wait the child_pid */
	else if (child_pid > 0)
	{
	/* The ppid wait the finish process of child_pid */
	/* Send a signal to stop the child_pid */
		waitpid(child_pid, &status, 0);
		kill(child_pid, SIGTERM);
	}
	else
	{
	/* The child_pid execute the command or exit if execve fail */
	        exe = execve(av[0], av, NULL);
		if (*av[0] == '\n')
		{
			free(av);
			return;
		}
		if (exe == -1)
			perror("exe");
		return;
	}
}
