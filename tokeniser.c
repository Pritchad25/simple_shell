#include "shell.h"

/**
 * **strtow - this function splits a string into words. Repeat
 * delimiters are ignored.
 * @d: the delimeter string
 * @str: the input string
 *
 * Return: a pointer to an array of strings (Success), or NULL (failure)
 */
char **strtow(char *str, char *d)
{
	char **s;
	int y, j, t, r, numwords = 0;

	if (str == NULL || str[0] == 0)
	{
		return (NULL);
	}
	if (!d)
		d = " ";
	for (y = 0; str[y] != '\0'; y++)
		if (!is_delim(str[y], d) && (is_delim(str[y + 1], d) || !str[y + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (y = 0, j = 0; j < numwords; j++)
	{
		while (is_delim(str[y], d))
			y++;
		t = 0;
		while (!is_delim(str[y + t], d) && str[y + t])
			t++;
		s[j] = malloc((t + 1) * sizeof(char));
		if (!s[j])
		{
			for (t = 0; t < j; t++)
				free(s[t]);
			free(s);
			return (NULL);
		}
		for (r = 0; r < t; r++)
			s[j][r] = str[y++];
		s[j][r] = 0;
	}
	s[j] = NULL;

	return (s);
}

/**
 * **strtow2 - this function splits a string into words
 * @d: the delimeter
 * @str: the input string
 * Return: a pointer to an array of strings (Success), or NULL (failure)
 */
char **strtow2(char *str, char d)
{
	char **s;
	int a, j, k, m, numWords = 0;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (a = 0; str[a] != '\0'; a++)
		if ((str[a] != d && str[a + 1] == d) ||
				(str[a] != d && !str[a + 1]) || str[a + 1] == d)
			numWords++;
	if (numWords == 0)
		return (NULL);
	s = malloc((1 + numWords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (a = 0, j = 0; j < numWords; j++)
	{
		while (str[a] == d && str[a] != d)
			a++;
		k = 0;
		while (str[a + k] != d && str[a + k] && str[a + k] != d)
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);

			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = str[a++];
		s[j][m] = 0;
	}
	s[j] = NULL;

	return (s);

}
