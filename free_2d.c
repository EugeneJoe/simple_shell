#include "shellheader.h"

/**
 * free_2d - frees an array of malloc'ed strings
 * @array: pointer to array of pointers to malloc'ed strings
 *
 * Return: no return value (void)
 */
void free_2d(char **array)
{
	int idx = 0;

	while (array[idx])
	{
		free(array[idx]);
		array[idx] = NULL;
		idx++;
	}
}
