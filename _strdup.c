#include "simpleshell.h"

/**
 * _strdup - returns a pointer to dup string, new allocated memory
 * @str: string to copy
 * Return: pointer to new string or NULL
 */

char *_strdup(char *str)
{
	char *a;
	unsigned int i, j, len = 0;

	if (str == NULL)
		return (NULL);
	for (j = 0; *(str + j) != '\0'; j++)
		len++;
	a = malloc((len + 1) * sizeof(char));
	if (a == NULL)
		return (NULL);
	for (i = 0; i < len; i++)
		*(a + i) = *(str + i);
	*(a + len) = '\0';
	return (a);
}
