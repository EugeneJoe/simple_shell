#include "shellheader.h"

/**
 * buildstr - builds a string with required parts
 * @str1: string 1
 * @str2: string 2
 * @str3: string 3
 *
 * Return: Fully built string
 */
char *buildstr(char *str1, char *str2, char *str3)
{
	char *fullstr;
	int len;

	len = _strlen(str1) + _strlen(str2) + _strlen(str3) + 1;
	fullstr = (char *)malloc(sizeof(char) * len);
	if (!fullstr)
	{
		free(fullstr);
		perror("Error: ");
		return (NULL);
	}
	fullstr[0] = '\0';
	fullstr = _strcat(fullstr, str1, str2, str3);
	return (fullstr);
}
