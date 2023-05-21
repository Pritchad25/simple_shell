#include "shell.h"

/**
 * list_len - this function determines length of linked list.
 * @h: the pointer to the first node.
 *
 * Return: the size of the list (Success)
 */
size_t list_len(const list_t *h)
{
	size_t p = 0;

	while (h)
	{
		h = h->next;
		p++;
	}

	return (p);
}

/**
 * list_to_strings - this function returns an array of strings of the list->str
 * @head: the pointer to the first node.
 *
 * Return: the array of strings (Success)
 */
char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t q = list_len(head), j;
	char *str;
	char **strs;

	if (!head || !q)
	{
		return (NULL);
	}
	strs = malloc(sizeof(char *) * (q + 1));
	if (!strs)
	{
		return (NULL);
	}

	for (q = 0; node; node = node->next, q++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < q; j++)
			{
				free(strs[j]);
			}
			free(strs);

			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[q] = str;
	}
	strs[q] = NULL;

	return (strs);
}

/**
 * print_list - this function prints all elements of a list_t linked list
 * @h: the pointer to the first node.
 *
 * Return: the size of the linked list (Success).
 */
size_t print_list(const list_t *h)
{
	size_t r = 0;

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;

		r++;
	}

	return (r);
}

/**
 * node_starts_with - this function returns the node whose string starts with
 * the prefix
 * @node: the pointer to the list head
 * @prefix: the string to match
 * @c: the next character after the prefix to match
 *
 * Return: the match node (Success) otherwise NULL.
 */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *p = NULL;

	while (node)
	{
		p = starts_with(node->str, prefix);
		if (p && ((c == -1) || (*p == c)))
		{
			return (node);
		}
		node = node->next;
	}

	return (NULL);
}

/**
 * get_node_index - this function gets the index of a node.
 * @node: the pointer to the node.
 * @head: the pointer to the list head.
 *
 * Return: the index of the node (Success), otherwise -1
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t s = 0;

	while (head)
	{
		if (head == node)
		{
			return (s);
		}
		head = head->next;
		s++;
	}

	return (-1);
}
