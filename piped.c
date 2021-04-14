#include "shelberton.h"

/**
 * piped - runs commands that have been piped to our shell
 *
 * Return: no return value
 */
void piped(void)
{
	bytes = getline(&command, &size, stdin);
	if (bytes != -1)
	{
		args = parsecommand(command);
		if (_strcmp(args[0], "exit") == 0)
		{
			shell_exit(args, my_env, command);
			break;
		}
		exec_func(args, my_env, command);
		bytes = 0;
	}
	else
	{
		perror("Error: ");
	}
}
