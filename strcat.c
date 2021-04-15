#include "shellheader.h"

/**
 * *_strcat - appends *src to the end of *dest
 * @dest: pointer to the destination string that will contain the
 * concatenated string
 * @src: pointer to the source string that will be appended to the dest string
 * @src2: pointer to 2nd source
 * @src3: pointer to 3rd source
 * Return: pointer to the resulting string dest
 */
char *_strcat(char *dest, char *src, char *src2, char *src3)
{
	int len = 0;
	int x, y, z;

	while (*(dest + len) != '\0')
		len++;
	for (x = 0; *(src + x); x++)
		*(dest + len + x) = *(src + x);
	for (y = 0; (*(src2 + y) != '\0'); y++)
		*(dest + len + x + y) = *(src2 + y);
	for (z = 0; (*(src3 + z) != '\0'); z++)
		*(dest + len + x + y + z) = *(src3 + z);
	*(dest + len + x + y + z) = '\0';
	return (dest);
}
