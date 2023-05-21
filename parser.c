#include "shell.h"

/**
 * is_cmd - this function determines if a file is an executable command.
 * @info: the info struct
 * @path: the path to the file.
 *
 * Return: 1 if its true (Success), otherwise 0.
 */
int is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
	{
		return (0);
	}
	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_chars - this function duplicates characters.
 * @pathstr: the Path string
 * @stop: the stopping index.
 * @start: the starting index.
 *
 * Return: the pointer to the new buffer.
 */
char *dup_chars(char *pathstr, int start, int stop)
{
	int o = 0, n = 0;
	static char buf[1024];

	for (n = 0, o = start; o < stop; o++)
	{
		if (pathstr[o] != ':')
		{
			buf[n++] = pathstr[o];
		}
	}
	buf[n] = 0;

	return (buf);
}

/**
 * find_path - this function finds the cmd in the path string.
 * @info: the info struct
 * @pathstr: the Path string
 * @cmd: the cmd to find
 *
 * Return: the full path of the cmd (Success), otherwise NULL.
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
	char *path;
	int m = 0, curr_pos = 0;

	if (!pathstr)
	{
		return (NULL);
	}
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
		{
			return (cmd);
		}
	}

	while (1)
	{
		if (!pathstr[m] || pathstr[m] == ':')
		{
			path = dup_chars(pathstr, curr_pos, m);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(info, path))
			{
				return (path);
			}
			if (!pathstr[m])
				break;

			curr_pos = m;
		}
		m++;
	}
	return (NULL);
}
