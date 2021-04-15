#include "shellheader.h"

/**
 * *_strchr - Locates the first occurrence of a character in a string
 * @s: String to be searched
 * @c: character to be searched for in string s
 *
 * Return: pointer to first occurence of c in s
 */
char *_strchr(char *s, char c)
{
	unsigned int index, length;
	char *found;

	found = 0;
	index = 0;
	length = 0;
	while (*(s + length) != '\0')
		length++;
	while (index <= length)
	{
		if (*(s + index) == c)
		{
			found = s + index;
			break;
		}
		index++;
	}
	if (found)
		return (found);
	else
		return (NULL);
}
