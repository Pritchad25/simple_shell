#include "shell.h"

/**
 * _erratoi - a function that converts a string to an integer
 * @s: a string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 *       -1 on error
 */
int _erratoi(char *s)
{
	int t = 0;
	unsigned long int res = 0;    /* res is the variable called result*/

	if (*s == '+')
		s++;  /* TODO: why does this make main return 255? */
	for (t = 0;  s[t] != '\0'; t++)
	{
		if (s[t] >= '0' && s[t] <= '9')
		{
			res *= 10;
			res += (s[t] - '0');
			if (res > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (res);
}

/**
 * print_error - a function that prints an error message
 * @info: a parameter & return info struct
 * @estr: string containing specified error type
 * Return: 0 if no numbers in string (Success) converted number otherwise
 *        -1 on error
 */
void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * print_d - the function prints a decimal (integer) number (base 10)
 * @input: this is an input
 * @fd: the filedescriptor to write to
 *
 * Return: number of characters printed (Success)
 */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int h, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
	{
		__putchar = _eputchar;
	}
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
	{
		_abs_ = input;
	}
	current = _abs_;
	for (h = 1000000000; h > 1; h /= 10)
	{
		if (_abs_ / h)
		{
			__putchar('0' + current / h);
			count++;
		}
		current %= h;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
 * convert_number - This is converter function, a clone of itoa
 * @num: number
 * @base: base
 * @flags: argument flags
 *
 * Return: string
 */
char *convert_number(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long m = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		m = -num;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[m % base];
		m /= base;
	} while (m != 0);

	if (sign)
	{
		*--ptr = sign;
	}
	return (ptr);
}

/**
 * remove_comments - This function replaces first instance of '#' with '\0'
 * @buf: An address of the string to modify
 *
 * Return: Always 0;
 */
void remove_comments(char *buf)
{
	int u;

	for (u = 0; buf[u] != '\0'; u++)
		if (buf[u] == '#' && (!u || buf[u - 1] == ' '))
		{
			buf[u] = '\0';
			break;
		}

}
