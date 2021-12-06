#include "simpleshell.h"

/**
 * builtin_alias - function that prints a list of all alias
 * @av: array of strings
 * Return: 0 always success
 */
int builtin_alias(char **av)
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
