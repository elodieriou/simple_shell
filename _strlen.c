#include "simpleshell.h"

/**
 * _strlen - returns the lenght of a string
 * @s: a string
 * Return: size of the string
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i])
		i++;
	return (i);
}
