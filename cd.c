#include "shellheader.h"

/**
 * _cd - changes current working directory to given directory
 * @args: parsed command line
 * @env: pointer to array of pointers to environment variables
 *
 * Return: Always 0
 */
int _cd(char **args, char **env)
{
	char *pwd, *cwd;
	int idx, status;

	pwd = _getenv("PWD", env);
	if (args[1] != NULL)
	{
		if (args[1][0] == '-')
		{
			cwd = _getenv("OLDPWD", env);
		}
		else if (args[1][0] == '$')
		{
			cwd = strtok(args[1], "$");
			cwd = strtok(NULL, " ");
			for (idx = 0; env[idx]; idx++)
				if (_strncmp(env[idx], cwd, _strlen(cwd)) == 0)
					cwd = _getenv(env[idx], env);
		}
		else
		{
			cwd = _strdup(args[1]);
		}
	}
	else
	{
		cwd = _getenv("HOME", env);
	}
	status = chdir(cwd);
	if (status == -1)
	{
/*		perror("Error :");*/
	}
	else
	{
		_setenv("OLDPWD", pwd, env);
		_setenv("PWD", cwd, env);
	}
	free(cwd);
	free(pwd);
	return (status);
}
