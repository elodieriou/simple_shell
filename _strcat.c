#include "simpleshell.h"

/**
 * _strcat - concatenates two strings
 * @dest: pointer to a string
 * @src: pointer to a string
 * Return: the pointer to dest
 */
char *_strcat(char *dest, char *src)
{
	int i, j;

	for (i = 0; dest[i] != '\0'; i++)
		;
	for (j = 0; src[j] != '\0'; j++)
		dest[i + j] = src[j];
	return (dest);
}
