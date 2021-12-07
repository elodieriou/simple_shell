#include "simpleshell.h"

/**
 * builtin_env - function that prints the current environment
 * @av: array of strings
 * Return: 0 always success
 */

int builtin_env(char **av)
{
	int i;
	(void)av;

	for (i = 0; environ[i]; i++)
	{
		_putstr(environ[i]);
		_putchar('\n');
	}
	return (0);
}
