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
