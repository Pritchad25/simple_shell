#include "shell.h"

/**
 * is_chain - this function tests if the current char in the buffer is a
 * chain delimeter
 * @buf: the char buffer
 * @info: the parameter struct
 * @p: the address of the current position in buf
 *
 * Return: 1 if it's a chain delimeter (Success), 0 otherwise.
 */
int is_chain(info_t *info, char *buf, size_t *p)
{
	size_t k = *p;

	if (buf[k] == '|' && buf[k + 1] == '|')
	{
		buf[k] = 0;
		k++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buf[k] == '&' && buf[k + 1] == '&')
	{
		buf[k] = 0;
		k++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (buf[k] == ';')
	{
		buf[k] = 0; /* replace the semicolon with NULL */
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
	{
		return (0);
	}
	*p = k;

	return (1);
}

/**
 * check_chain - this function looks at the checks we should continue
 * chaining based on the last status.
 * @p: the address of the current position in buf.
 * @buf: the char buffer
 * @info: the parameter struct
 * @i: the starting position in the buf
 * @len: the length of the buf
 * Return: void
 */
void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
	size_t j = *p;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}

	*p = j;
}

/**
 * replace_alias - this function replaces the aliases in the tokenised string
 * @info: the parameter struct
 *
 * Return: 1 if the alias has been replaced (Success), 0 otherwise.
 */
int replace_alias(info_t *info)
{
	char *p;
	int a;
	list_t *node;

	for (a = 0; a < 10; a++)
	{
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
		{
			return (0);
		}
		free(info->argv[0]);
		p = _strchr(node->str, '=');
		if (!p)
		{
			return (0);
		}
		p = _strdup(p + 1);
		if (!p)
		{
			return (0);
		}
		info->argv[0] = p;
	}

	return (1);
}

/**
 * replace_vars - this function replaces vars in the tokenised string
 * @info: the parameter struct
 *
 * Return: 1 if the vars have been replaced (Success), 0 otherwise.
 */
int replace_vars(info_t *info)
{
	int s = 0;
	list_t *node;

	for (s = 0; info->argv[s]; s++)
	{
		if (info->argv[s][0] != '$' || !info->argv[s][1])
		{
			continue;
		}
		if (!_strcmp(info->argv[s], "$?"))
		{
			replace_string(&(info->argv[s]),
					_strdup(convert_number(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[s], "$$"))
		{
			replace_string(&(info->argv[s]),
					_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(info->env, &info->argv[s][1], '=');
		if (node)
		{
			replace_string(&(info->argv[s]),
					_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		replace_string(&info->argv[s], _strdup(""));
	}

	return (0);
}

/**
 * replace_string - this function replaces a string
 * @new: the new string
 * @old: the address of the old string
 *
 * Return: 1 if the string has been replaced (Success), 0 otherwise.
 */
int replace_string(char **old, char *new)
{
	free(*old);
	*old = new;

	return (1);

}
