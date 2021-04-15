#include "shellheader.h"

/**
 * _strtok - breaks a string into a sequence of zero or more non-empty tokens.
 * @str: pointer to string to be broken up
 * @delim: pointer to string that is delimeter for the tokens
 *
 * Return: pointer to the next token or NULL if there are no more tokens
 */
char *_strtok(char *str, const char *delim)
{
	static char *next;
	char *buf;
	char *curr;
	int idx = 0;

	if (str != NULL)
		curr = str;
	else if (*next != '\0')
		curr = next;
	else if (*next == '\0')
		return (NULL);
	buf = (char *)malloc(sizeof(char) * 1024);
	if (!buf)
	{
		free(buf);
		perror("Error: ");
		return (NULL);
	}
	while (*curr != *delim && *curr != '\0')
	{
		buf[idx] = *curr;
		idx++;
		curr++;
	}
	buf[idx] = '\0';
	if (curr != '\0')
		next = ++curr;
	else
		next = curr;
	return (buf);
}
