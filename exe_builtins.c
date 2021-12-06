#include "simpleshell.h"

/**
 * exe_builtins - function that execute builtins
 * @av: an array of string (command passed by user)
 * Return: builtin funtion or execute av
 */
int exe_builtins(char **av)
{
	builtin_t list[] = {
		{"exit", builtin_exit},
		{"env", builtin_env},
		{"help", builtin_help},
		{NULL, NULL}};
	int i;

	for (i = 0; list[i].name != NULL; i++)
		if (_strcmp(av[0], list[i].name) == 0)
		{
			list[i].f(av);
			return (0);
		}
	return (-1);
}
