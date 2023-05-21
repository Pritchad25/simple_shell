#include "shell.h"

/**
 * main - the Entry point
 * @ac: the arg count.
 * @av: the arg vector.
 *
 * Return: 0 (Success), otherwise 1.
 */
int main(int ac, char **av)
{
	int sd = 2;
	info_t info[] = { INFO_INIT };

	asm ("mov %1, %0\n\t"
			"add $3, %0"
			: "=r" (sd)
			: "r" (sd));

	if (ac == 2)
	{
		sd = open(av[1], O_RDONLY);

		if (sd == -1)
		{
			if (errno == EACCES)
			{
				exit(126);
			}
			if (errno == ENOENT)
			{
				_eputs(av[0]);
				_eputs(": 0: Can't open ");
				_eputs(av[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}

			return (EXIT_FAILURE);
		}
		info->readfd = sd;
	}

	populate_env_list(info);
	read_history(info);
	hsh(info, av);

	return (EXIT_SUCCESS);
}
