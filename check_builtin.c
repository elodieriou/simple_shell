#include "simpleshell.h"

/**
 * check_builtin - function that check if the command is a builtin
 * @av: an array of string
 * Return: 0 on success, -1 on error
 */

int check_builtin(char **av)
{
	char *list_builtin[] = {"exit", "env", "help", NULL};
	int i;

	for (i = 0; list_builtin[i]; i++)
		if (_strcmp(list_builtin[i], av[0]) == 0)
			return (0);
	return (-1);
}
