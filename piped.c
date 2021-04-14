#include "shelberton.h"

/**
 * piped - runs commands that have been piped to our shell
 * @my_env: pointer to array of pointers to environment variables
 *
 * Return: no return value
 */
void piped(char **my_env)
{
        ssize_t bytes;
        size_t size = 0;
        char **args, *command = NULL;

	bytes = getline(&command, &size, stdin);
	if (bytes != -1)
	{
		args = parsecommand(command);
		if (_strcmp(args[0], "exit") == 0)
		{
			shell_exit(args, my_env, command);
		}
		exec_func(args, my_env, command);
		bytes = 0;
	}
}
