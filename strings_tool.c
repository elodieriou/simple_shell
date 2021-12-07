#include "simpleshell.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _putstr - function that print a string
 * @s: a pointer to a string
 * Return: the number of bytes of the string
 */

int _putstr(char *s)
{
	int i;

	if (s == NULL)
		return (-1);
	for (i = 0; s[i]; i++)
		_putchar(s[i]);
	return (i);
}

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

/**
 * _strcmp - function that compares two strings
 * @s1: string compare to string s2
 * @s2: string compare to sting s1
 * Return: an integer less than equal, greater or lower
 */

int _strcmp(char *s1, const char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
		{
			return (0);
		}
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
 * _strcpy - copies the string pointed to by src to buffer
 * @src: pointer to string
 * @dest: pointer to buffer
 * Return: the pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
	int len = _strlen(src);
	int c;

	for (c = 0; c <= len; c++)
		dest[c] = src[c];
	return (dest);
}
