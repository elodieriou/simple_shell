#include "simpleshell.h"

/**
 * _realloc - function that reallocates a memory block using malloc and free
 * @old_size: is the size in bytes of the allocated space for ptr
 * @new_size: is the new size in bytes of the new memory block
 * @ptr: is a pointer with the previously memory allocated
 * Return: the new memory allocated
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *nptr;

	if (new_size == old_size)
		return (ptr);
	if (ptr == 0)
	{
		free(ptr);
		ptr = malloc(new_size);
		return (ptr);
	}
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	nptr = malloc(new_size);
	if (nptr == 0)
		return (NULL);
	_memcpy(nptr, ptr, old_size);
	return (nptr);
}

/**
 * _getenv - gets an environment variable. (without using getenv)
 * @name: name of the value (var)
 * Return: string or 0 if failed
 */

char *_getenv(const char *name)
{
	char *token, **tmp;
	int i;

	tmp = malloc(sizeof(char *));
	for (i = 0; environ[i] != NULL; i++)
	{
		tmp[i] = _realloc(tmp, sizeof(tmp),
				  (_strlen(environ[i]) * sizeof(char) + 1));
		tmp[i] = _strdup(environ[i]);
	}
	for (i = 0; tmp[i] != NULL; i++)
	{
		token = strtok(tmp[i], "=");
		if (_strcmp(token, name) == 0)
		{
			token = strtok(NULL, "=");
			free(tmp);
			return (token);
		}
	}
	free(tmp);
	return (0);
}

/**
 * _memcpy - fucntion that copies memory area
 * @dest: copy of memory area src
 * @src: memory area copy on dest
 * @n: n bytes copies
 * Return: value of dest
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		dest[i] = ((char *)src)[i];
	return (dest);
}

/**
 * _memset - function that fills memory with a constant byte
 * @s: pointer to a character
 * @b: a character
 * @n: n bytes of the memory area pointed by s
 * Return: value of s
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}
