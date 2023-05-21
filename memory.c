#include "shell.h"

/**
 * bfree- this function frees a pointer and NULLs the address
 * @ptr: the address of the pointer to free.
 *
 * Return: 1 if the pointer is freed (Success), otherwise 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;

		return (1);
	}

	return (0);
}
