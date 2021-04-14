#include "shelberton.h"

/**
 * exec_func - executes given commands in child process
 * @args: command and arguments read from stdin
 * @env: array of environment variables
 * @command: string read from stdin
 *
 * Return: 0
 */
int exec_func(char **args, char **env, char *command __attribute__((unused)))
{
	int status;
	pid_t child_pid;

	if (built_in(args, env) != 0)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error: ");
			return (-1);
		}
		if (child_pid == 0)
		{
			if (_strncmp(args[0], "echo", 4) == 0)
				check_args(args, env);
			if (_strncmp(args[0], "./", 2) != 0)
				check_path(args, env);
			if (execve(args[0], args, env) == -1)
			{
				perror("Error: ");
				return (-1);
			}
		}
		else
		{
			wait(&status);
		}
	}
	return (0);
}
