#include <stdio.h>

/**
 * main - prints all the arguments passed to the program
 * @ac: Number of arguments passed to the program
 * @av: pointer to an array of pointers to the arguments to the program
 *
 * Return: Always 0
 */
int main(int ac __attribute__((unused)), char **av)
{
	int idx = 0;

	while (av[idx] != NULL)
	{
		printf("Argument %d: %s\n", idx, av[idx]);
		idx++;
	}
	return (0);
}
