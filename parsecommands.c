#include "shellheader.h"

/**
 * parsecommand - splits command line into array of words
 * @command: string read from stdin
 *
 * Return: Array of strings/words read from stdin
 */
char **parsecommand(char *command)
{
	char *token, *temp, **args;
	int i, len = 0;

	temp = _strchr(command, '#');
	if (temp != NULL)
		*temp = '\0';
	for (i = 0; command[i]; i++)
	{
		if (command[i] == ' ' || command[i] == '\n')
			len++;
	}
	len++;
	args = malloc(sizeof(char *) * len);
	if (!args)
	{
		free(args);
		return (NULL);
	}
	temp = strtok(command, "\n");
	token = strtok(temp, " ");
	for (i = 0; token; i++)
	{
		args[i] = _strdup(token);
		token = strtok(NULL, " ");
	}
	args[i] = NULL;
	if (*args != NULL)
		return (args);
	else
		return (NULL);
}
