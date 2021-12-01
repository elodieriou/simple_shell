#include "simpleshell.h"

/**
 * _putstr - function that print a string
 * @s: a pointer to a string
 * Return: the number of bytes of the string
 */

int _putstr(char *s)
{
	int i;

	if (str == NULL)
		return (-1);
	for (i = 0; s[i]; i++)
		_putchar(s[i]);
	return (i);
}
