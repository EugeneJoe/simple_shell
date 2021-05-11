#include "shellheader.h"
/**
  * _getline - reads user inputfrom STDIN.
  * @argv: pointer to array of pointers to arguments to the program
  *
  * Return: Input.
  */
char *_getline(char **argv)
{
	int i, buffsize = BUFSIZE, rd;
	char c = 0;
	char *buff = malloc(buffsize);

	if (buff == NULL)
	{
		free(buff);
		return (NULL);
	}

	for (i = 0; c != EOF && c != '\n'; i++)
	{
		fflush(stdin);
		rd = read(STDIN_FILENO, &c, 1);
		if (rd == 0)
		{
			free(buff);
			perror(argv[0]);
			exit(EXIT_SUCCESS);
		}
		buff[i] = c;
		if (buff[0] == '\n')
		{
			free(buff);
			return ("\0");
		}
		if (i >= buffsize)
		{
			buff = _realloc(buff, buffsize, buffsize + 1);
			if (buff == NULL)
			{
				perror(argv[0]);
				return (NULL);
			}
		}
	}
	buff[i] = '\0';
	printf("%s\n", buff);
	hash_handle(buff);
	return (buff);
}

/**
  * hash_handle - purges anything after # from input.
  * @buff: input.
  *
  * Return: VOID.
  */
void hash_handle(char *buff)
{
	int i;

	for (i = 0; buff[i] != '\0'; i++)
	{
		if (buff[i] == '#')
		{
			buff[i] = '\0';
			break;
		}
	}
}
