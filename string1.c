#include "shell.h"

/**
 * _strcpy - this function copies a string
 * @src: the source
 * @dest: the destination
 *
 * Return: the pointer to the destination
 */
char *_strcpy(char *dest, char *src)
{
	int x = 0;

	if (dest == src || src == 0)
	{
		return (dest);
	}
	while (src[x])
	{
		dest[x] = src[x];
		x++;
	}
	dest[x] = 0;

	return (dest);
}

/**
 * _strdup - this function duplicates a string
 * @str: the string to duplicate
 *
 * Return: the pointer to the duplicated string (Success)
 */
char *_strdup(const char *str)
{
	char *ret;
	int len = 0;

	if (str == NULL)
	{
		return (NULL);
	}
	while (*str++)
	{
		len++;
	}
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
	{
		return (NULL);
	}
	for (len++; len--;)
	{
		ret[len] = *--str;
	}
	return (ret);
}

/**
 * _puts - this function prints an input string
 * @str: the string to be printed
 *
 * Return: void
 */
void _puts(char *str)
{
	int b = 0;

	if (!str)
	{
		return;
	}

	while (str[b] != '\0')
	{
		_putchar(str[b]);
		b++;
	}
}

/**
 * _putchar - this function writes the character c to the stdout
 * @c: the character to print
 *
 * Return: 1 (Success), otherwise -1 (error) and errno is set appropriately
 */
int _putchar(char c)
{
	static char buf[WRITE_BUF_SIZE];
	static int d;

	if (c == BUF_FLUSH || d >= WRITE_BUF_SIZE)
	{
		write(1, buf, d);
		d = 0;
	}

	if (c != BUF_FLUSH)
	{
		buf[d++] = c;
	}
	return (1);

}
