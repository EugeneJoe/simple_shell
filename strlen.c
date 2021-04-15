#include "shellheader.h"

/**
 * _strlen - returns the length of a string
 * @str: pointer to the string
 *
 * Return: length of string or 0
 */
int _strlen(char *str)
{
	int len = 0;

	while (*(str + len))
		len++;
	return (len);
}
