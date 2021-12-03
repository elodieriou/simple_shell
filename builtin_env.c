#include "simpleshell.h"

/**
 * builtin_env - function that prints the current environment
 * Return: 0 always success
 */
int builtin_env(void)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		_putstr(environ[i]);
		_putchar('\n');
	}
	return (0);
}
