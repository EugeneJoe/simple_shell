#include "shellheader.h"

/**
 * _unsetenv - Remove an environment variable
 * @var: name of variable to be removed
 * @env: pointer to array of pointers to environment variables
 *
 * Return: 0 on success
 */
int _unsetenv(char *var, char **env)
{
	char **temp;
	int var_len;

	var_len = _strlen(var);
	while (*env)
	{
		if (_strncmp(*env, var, var_len))
		{
			temp = env;
			free(temp[0]);
			do {
				env[0] = env[1];
				temp++;
			} while (*temp);
		}
	}
	return (0);
}
