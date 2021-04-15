#include "shellheader.h"

/**
 * tostring - converts an int to a string
 * @num: int to be converted
 *
 * Return: pointer to string containing int
 */
char *tostring(int num)
{
	char *str = NULL;
	int i, rem, len = 0, n;

	n = num;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
	{
		free(str);
		perror("Error: ");
		return (NULL);
	}
	for (i = 0; i < len; i++)
	{
		rem = num % 10;
		num = num / 10;
		str[len - (i + 1)] = rem + '0';
	}
	str[len] = '\0';
	return (str);
}
