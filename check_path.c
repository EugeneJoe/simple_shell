#include "shellheader.h"

/**
 * check_path - checks whether commands are found in PATH environment variable
 * @args: pointer array of pointers to strings that are arguments from stdin
 * @env: pointer to array of pointers to the environment variables
 *
 * Return: 0 on success
 */
int check_path(char **args, char **env)
{
	struct stat st;
	char *fullname, *path, *value;

	path = _getenv("PATH", env);
	value = strtok(path, ":");
	while (value != NULL)
	{
		fullname = buildstr(value, "/", args[0]);
		if (stat(fullname, &st) == 0)
		{
			free(args[0]);
			args[0] = _strdup(fullname);
			free(fullname);
			free(path);
			return (0);
		}
		free(fullname);
		value = strtok(NULL, ":");
	}
	free(path);
	return (1);
}
