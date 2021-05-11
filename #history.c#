#include "shellheader.h"
/**
  * history - Populates file with user input commands.
  * @input:commands input by useer.
  * Return: 0 on SUCCESS, -1 on ERROR.
  */
int history(char *input)
{
	char *filename = ".simple_shell_history";
	ssize_t fd, w;
	int len = 0;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_RDWR | O_APPEND, 00600);
	if (fd < 0)
		return (-1);
	if (input)
	{
		while (input[len])
			len++;
		w = write(fd, input, len);
		if (w < 0)
			return (-1);
	}
	return (1);
}
/**
  * disp_hist - displays history of user input.
  * @c: parsed command.
  * @s: status of last execution.
  *
  * Return: 0 on SUCESS, -1 ON ERROR.
  */
int disp_hist(__attribute__((unused))char **c, __attribute__((unused))int s)
{
	char *filename = ".simple_shell_history";
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	int i = 0;
	char *er;

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		return (-1);
	}
	while ((getline(&line, &len, fp)) != -1)
	{
		i++;
		er = tostring(i);
		PRINTER(er);
		free(er);
		PRINTER(" ");
		PRINTER(line);
	}
	if (line)
		free(line);
	fclose(fp);
	return (0);
}
/**
  * free_env - free environment variable array.
  * @env: environment variables.
  *
  * Return: VOID.
  */
void free_env(char **env)
{
	int i;

	for (i = 0; env[i]; i++)
	{
		free(env[i]);
	}
}
