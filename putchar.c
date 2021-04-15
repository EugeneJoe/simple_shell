#include "shellheader.h"

/**
  * _putchar - prints char to STDOUT.
  * @c: char to be printed.
  *
  * Return: 1 on SUCCESS.
  * -1 on error and errno set appropriately.
  */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
