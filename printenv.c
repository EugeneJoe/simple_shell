#include "shellheader.h"

/**
 * printenv - prints the current environment
 * @env: pointer to array of pointers to environment variables
 *
 * Return: no return value
 */
int printenv(char **env)
{
	char **my_env = env;
	int len = 0;

	while (*my_env)
	{
		while (*(*my_env + len))
			len++;
		write(STDOUT_FILENO, *my_env, len);
		write(STDOUT_FILENO, "\n", 2);
		len = 0;
		my_env++;
	}
	return (0);
}
