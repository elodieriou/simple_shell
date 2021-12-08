#include "simpleshell.h"

/**
 * _strdup - returns a pointer to dup string, new allocated memory
 * @str: string to copy
 * Return: pointer to new string or NULL
 */

char *_strdup(char *str)
{
	char *a;
	unsigned int i, len;

	if (str == NULL)
		return (NULL);
	for (len = 0; str[len] != '\0'; len++)
		;
	a = malloc((len + 1) * sizeof(char));
	if (a == NULL)
		return (NULL);
	for (i = 0; i < len; i++)
		a[i] = str[i];
	return (a);
}

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

/**
 * *_strncmp - function that compare the n first characters of two strings
 * @s1: string that receives a copy of variable src string
 * @s2: string copy in the variable dest string
 * @n: n
 * Return: a pointer to the resulting string dest
 */

int _strncmp(char *s1, char *s2, int n)
{
	int i;

	for (i = 0; s1[i] && s2[i] && i < n; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}
