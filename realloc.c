#include "shell.h"

/**
 * *_memset - this function fills memory with a constant byte
 * @s: the pointer to the memory area.
 * @b: the byte to fill *s with.
 * @n: the amount of bytes to be filled
 *
 * Return: the pointer to the memory area s (Success)
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int k;

	for (k = 0; k < n; k++)
	{
		s[k] = b;
	}
	return (s);
}

/**
 * ffree - this function frees a string of strings.
 * @pp: the string of strings
 */
void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
	{
		return;
	}
	while (*pp)
	{
		free(*pp++);
	}
	free(a);
}

/**
 * _realloc - this function reallocates a block of memory.
 * @ptr: the pointer to the previous block that was malloc'ed.
 * @new_size: the byte size of the new block.
 * @old_size: the byte size of the previous block.
 *
 * Return: the pointer to the new block (Success)
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
	{
		return (malloc(new_size));
	}
	if (!new_size)
	{
		return (free(ptr), NULL);
	}
	if (new_size == old_size)
	{
		return (ptr);
	}

	p = malloc(new_size);
	if (!p)
	{
		return (NULL);
	}

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
	{
		p[old_size] = ((char *)ptr)[old_size];
	}
	free(ptr);

	return (p);
}
