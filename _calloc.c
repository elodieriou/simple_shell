#include "simpleshell.h"

/**
 * _calloc - function that allocates memory for an array, using malloc
 * @nmemb: n elements
 * @size: size of bytes
 * Return: a pointer to the allocated memory of array
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *ar;
	unsigned int mul = 0;

	if (nmemb == 0 || size == 0)
		return (NULL);

	mul = nmemb * size;

	ar = malloc(mul);
	if (ar == 0)
		return (NULL);

	_memset(ar, 0, mul);
	return (ar);
}
