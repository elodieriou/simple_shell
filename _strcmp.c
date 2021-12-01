#include "main.h"

/**
 * _strcmp - function that compares two strings
 *
 * @s1: string compare to string s2
 * @s2: string compare to sting s1
 *
 * Return: an integer less than equal, greater or lower
 */
int _strcmp(char *s1, char *s2)
{
	while(*s1 == *s2)
	{
		if(*s1 == '\0')
		{
			return (0);
		}
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
