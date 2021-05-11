#include <stdio.h>
#include <stdlib.h>

extern char **environ;

/**
 * main - prints the environment using the global variable environ
 *
 * Return: Always 0
 */
int main(void)
{
	char **env = environ;

	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
	return (0);
}
