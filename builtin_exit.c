#include "simpleshell.h"

/**
 * builtin_exit - function that exit the shell
 * Return: 0 always success
 */
int builtin_exit(char **av)
{
	(void)av;

	exit(EXIT_FAILURE);
}
