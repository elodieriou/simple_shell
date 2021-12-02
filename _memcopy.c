#include "simpleshell.h"

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
