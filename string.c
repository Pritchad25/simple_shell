#include "shell.h"

/**
 * _strlen - this function returns the length of a string.
 * @s: the string whose length is to be returned.
 *
 * Return: the length of the string as a number (Success)
 */
int _strlen(char *s)
{
	int e = 0;

	if (!s)
	{
		return (0);
	}
	while (*s++)
	{
		e++;
	}

	return (e);
}

/**
 * _strcmp - this function performs lexicographic comparison of two strings.
 * @s1: the first string.
 * @s2: the second string.
 *
 * Return: positive if s1 > s2, zero if s1 == s2, negative if s1 < s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
		s1++;
		s2++;
	}
	if (*s1 == *s2)
	{
		return (0);
	}
	else
	{
		return (*s1 < *s2 ? -1 : 1);
	}
}

/**
 * starts_with - this function checks if the needle starts with haystack
 * @haystack: the string to search.
 * @needle: the substring to find.
 * Return: the address of the next char of haystack (Success), otherwise NULL.
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
	{
		if (*needle++ != *haystack++)
		{
			return (NULL);
		}
	}
	return ((char *)haystack);
}

/**
 * _strcat - the function concatenates two strings
 * @src: the source buffer
 * @dest: the destination buffer
 *
 * Return: the pointer to the destination buffer
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
	{
		dest++;
	}
	while (*src)
	{
		*dest++ = *src++;
	}
	*dest = *src;

	return (ret);

}
