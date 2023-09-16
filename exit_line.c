#include "shell.h"

/**
 * exit_shell - fucntion to handle the "exit" command.
 * @inptsh: pointer to the data structure that holds.
 * command-related information
 * Return: 0 on success
 */
int exit_shell(inpt_shell *inptsh)
{
	unsigned int ustatus;
	int is_digit;
	int str_len;
	int big_number;

	if (inptsh->args[1] != NULL)
	{
		ustatus = _atoi(inptsh->args[1]);
		is_digit = _isdigit(inptsh->args[1]);
		str_len = _strlen(inptsh->args[1]);
		big_number = ustatus > (unsigned int)INT_MAX;
		if (!is_digit || str_len > 10 || big_number)
		{
			get_error(inptsh, 2);
			inptsh->status = 2;
			return (1);
		}
		inptsh->status = (ustatus % 256);
	}
	return (0);
}
