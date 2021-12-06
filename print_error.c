#include "simpleshell.h"

/**
 * print_error - function that handle the errors
 */
void print_error(int num, char **av)
{
	_putstr("hsh: ");
	print_number(num);
	_putstr(": ");
	_putstr(av[0]);
	_putstr(":  not found\n");
}
