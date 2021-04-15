#include "shellheader.h"
/**
  * display_help - displays builtin help page.
  * @cmd: Parsed input command.
  * @er: status of last executed commaand.
  *
  * Return: 0 on success, -1 on failure.
  */
int display_help(char **cmd, __attribute__((unused))int er)
{
	int fd, fw, rd = 1;
	char c;

	fd = open(cmd[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error");
		return (0);
	}
	while (rd > 0)
	{
		rd = read(fd, &c, 1);
		fw = write(STDOUT_FILENO, &c, rd);
		if (fw < 0)
		{
			return (-1);
		}
	}
	_putchar('\n');
	return (0);
}

/**
  * _realloc - reallocates memory block.
  * @ptr: Pointer.
  * @old_size: previous size of pointer.
  * @new_size: new size of pointer.
  *
  * Return: void pointer realloc mem.
  */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *result;

	if (new_size == old_size)
		return (ptr);
	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}

	result = malloc(new_size);
	if (result == NULL)
		return (NULL);
	if (ptr == NULL)
	{
		fill_an_array(result, '\0', new_size);
		free(ptr);
	}
	else
	{
		_memcpy(result, ptr, old_size);
		free(ptr);
	}
	return (result);
}

/**
  * _memcpy - copy byte froem src to dest.
  * @dest: destination pointer.
  * @src: source pointer.
  * @n: SIZE.
  *
  * Return: VOID Pointer.
  */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}

/**
  * fill_an_array - fioll array with constant bytes.
  * @a: void pointer.
  * @el: integer.
  * @len: length of array.
  *
  * Return: void pointer.
  */
void *fill_an_array(void *a, int el, unsigned int len)
{
	char *p = a;
	unsigned int i = 0;

	while (i < len)
	{
		*p = el;
		p++;
		i++;
	}
	return (a);
}
