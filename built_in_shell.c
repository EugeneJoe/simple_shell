#include "shellheader.h"

/**
 * built_in - works out which built-in functions to be called when necessary
 * @args: arguments passed on command line
 * @env: double pointer to our environment
 *
 * Return: 0 on success, -1 if failed
 */
int built_in(char **args, char **env)
{
	if (_strcmp(args[0], "env") == 0)
	{
		return (printenv(env));
	}
	else if (_strcmp(args[0], "setenv") == 0)
	{
		return (_setenv(args[1], args[2], env));
	}
	else if (_strcmp(args[0], "unsetenv") == 0)
	{
		return (_unsetenv(args[1], env));
	}
	else if (_strcmp(args[0], "cd") == 0)
	{
		return (_cd(args, env));
	}
	else if (_strcmp(args[0], "help") == 0)
	{
		display_help(args, 0);
		return (0);
	}
	else if (_strcmp(args[0], "history") == 0)
	{
		return (disp_hist(args, 0));
	}
	else if (_strcmp(args[0], "^C") == 0)
	{
		handle_sigint(SIGINT);
		return (0);
	}
	return (-1);
}
