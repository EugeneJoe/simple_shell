#include "shellheader.h"

/**
 * check_args - check for arguments that start with '$' and expand it
 * @args: pointer to aray of pointers to arguments from stdin
 * @env: pointer to array of pointers to environment variables
 *
 * Return: Always 0
 */
int *check_args(char **args, char **env)
{
	int idx = 0;
	char *exp_arg = NULL, *temp = NULL;

	if (args[1][0] == '$')
	{
		if (args[1][1] == '$')
		{
			idx = getpid();
			exp_arg = tostring(idx);
		}
		else
		{
			temp = strtok(args[1], "$");
			for (idx = 0; env[idx]; idx++)
			{
				if (_strncmp(env[idx], temp, _strlen(temp)) == 0)
				{
					exp_arg = _getenv(env[idx], env);
					break;
				}
			}
		}
	}
	if (exp_arg != NULL)
	{
		free(args[1]);
		args[1] = _strdup(exp_arg);
	}
	free(exp_arg);
	return (0);
}
