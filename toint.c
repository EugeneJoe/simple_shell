#include "shellheader.h"

/**
 * toint - converts number in string to integere variable
 * @str: pointer to string containing number
 *
 * Return: int
 */
int toint(char *str)
{
	int i, num = 0, sign = 0;

	for (i = 0; str[i]; i++)
	{
		if (str[i] == '-')
		{
			i++;
			sign++;
		}
		if (str[i] > 47 && str[i] < 58)
		{
			if (i == 0 || (i == 1 && sign > 0))
				num = str[i] - 48;
			else
				num = num * 10 + (str[i] - 48);
		}
		else
			return (1);
	}
	if (sign > 0)
		num *= -1;
	return (num);
}
