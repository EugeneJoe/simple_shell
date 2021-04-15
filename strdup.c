#include "shellheader.h"

/**
 * _strdup - makes a duplicate of a string pointed to by str
 * @str: pointer to string to be duolicated
 *
 * Description: mallocs a buffer of size length of str and copies str to buffer
 * Return: pointer to buffer containing duplicated string
 */
char *_strdup(char *str)
{
	int x, y;
	char *dup = NULL;

	if (str != NULL)
	{
		x = _strlen(str);
		dup = (char *)malloc(sizeof(char) * (x + 2));
		if (!dup)
		{
			perror("Error: ");
			free(dup);
			return (0);
		}
		for (y = 0; y <= x; y++)
			*(dup + y) = *(str + y);
		*(dup + y) = '\0';
		return (dup);
	}
	return (NULL);
}
