#include "shellheader.h"

/**
 * _strcmp - compares two strings s1 and s2
 * @s1: first string to be compared
 * @s2: second string to be compared
 *
 * Return: 0 if s1 and s2 are the same,
 * if ASCII code of 1st umnatched character is less than the second, -ve value
 * if ASCII code of 1st unmatched character is more than the second, +ve value
 */
int _strcmp(char *s1, char *s2)
{
	int diff, count, len1, len2, end;

	len1 = 0;
	while (*(s1 + len1) != '\0')
		len1++;
	len2 = 0;
	while (*(s2 + len2) != '\0')
		len2++;
	diff = 0;
	count = 0;
	end = len1 < len2 ? len1 : len2;
	while (count < end)
	{
		if (*(s1 + count) != *(s2 + count))
		{
			diff = *(s1 + count) - *(s2 + count);
			break;
		}
		count++;
	}
	return (diff);
}
