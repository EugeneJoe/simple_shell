#include "shellheader.h"

/**
 * shell_exit - exit shell with given status
 * @args: arguments passed on command line
 * @env: double pointer to environment variables
 * @command: pointer to string read from stdin
 *
 * Return: no return value
 */
void shell_exit(char **args, char **env, char *command)
{
	int status = 0;

	if (args[1] != NULL)
	{
		status = toint(args[1]);
		free(command);
		free_2d(env);
		free_2d(args);
		free(args);
		exit(status);
	}
	else
	{
		free(command);
		free_2d(env);
		free_2d(args);
		free(args);
		exit(status);
	}
}
