#include "hsh.h"

/**
 * main - entry point
 * @argc: arg count
 * @argv: arg vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char **argv)
{
	information_t information[] = { INFORMATION_INITIATION };
	int file_pointer = 2;

	asm ("mov %1, %0\n\t"
			"add $3, %0"
			: "=r" (file_pointer)
			: "r" (file_pointer));

	if (argc == 2)
	{
		file_pointer = open(argv[1], O_RDONLY);
		if (file_pointer == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(argv[0]);
				_eputs(": 0: Can not open ");
				_eputs(argv[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		information->readfd = file_pointer;
	}
	_env_lst(information);
	read_history(information);
	hsh(information, argv);
	return (EXIT_SUCCESS);
}



