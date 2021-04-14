#include "shelberton.h"

/**
 * main - a simple shell that can run commands with their full path, without
 * any arguments
 *
 * Return: Always 0
 */
int main(void)
{
	ssize_t bytes, k = 0;
	size_t size = 0;
	char **args, *my_env[60], *command = NULL;

	signal(SIGINT, handle_sigint);
	for (k = 0; environ[k]; k++)
		my_env[k] = _strdup(environ[k]);
	my_env[k] = NULL;
/*	if (!isatty(STDIN_FILENO))
		piped(my_env);*/
	while (1)
	{
		write(STDOUT_FILENO, "$ ", 3);
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
		free_2d(args);
		free(args);
	}
	free_2d(args);
	free(args);
	free_2d(my_env);
	return (0);
}
