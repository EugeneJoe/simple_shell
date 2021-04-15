#include "shellheader.h"

/**
 * _strncmp - compares n bytes of string s2 with s1
 * @s1: first string to be compared
 * @s2: second string to be compared
 * @n: number of bytes to compare
 *
 * Return: 0 if s1 and s2 are the same,
 * if ASCII code of 1st umnatched character is less than the second, -ve value
 * if ASCII code of 1st unmatched character is more than the second, +ve value
 */
int _strncmp(char *s1, char *s2, int n)
{
	int diff, count;

	diff = 0;
	count = 0;
	while (count < n && s2[count])
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
