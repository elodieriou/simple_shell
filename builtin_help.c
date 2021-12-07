#include "simpleshell.h"

/**
 * builtin_help - function that help the user
 * @av: an array of strings
 * Return: 0 always success
 */

int builtin_help(char **av)
{
	if (av[1] == NULL)
		_putstr("help: not found\n");

	else if (_strcmp(av[1], "exit") == 0)
		_putstr("exit: Terminate the simple shell program\n");
	else if (_strcmp(av[1], "env") == 0)
		_putstr("env: Prints the curent environment variable\n");

	else if (_strcmp(av[1], "help") == 0)
		_putstr("help: Prints usage of a buildin command.\n");

	return (0);
}
