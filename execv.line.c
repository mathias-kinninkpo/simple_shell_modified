#include "shell.h"

/**
 * exec_line - function is responsible for determining whether the
 * input command is a bulit-in command or an external command
 * and then dispatching the appropriate action
 * @inptsh: pointer to the data structure (argt)
 * that holds command- related information
 * Return: 1 on success
 */
int exec_line(inpt_shell *inptsh)
{
	int (*builtin)(inpt_shell *inptsh);

	if (inptsh->argt[0] == NULL)
		return (1);
	builtin = get_builtin(inptsh->argt[0]);

	if (builtin != NULL)
		return (builtin(inptsh));

	return (cmd_execut(inptsh));
}
