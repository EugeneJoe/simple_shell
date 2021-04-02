#include <stdio.h>

/**
 * main - prints "$ ", waits for the user to enter a command, prints it on the
 * next line.
 *
 * Return: Always 0
 */
int main(void)
{
	char buf[1024];
	int bytes;

	printf("$ ");
	bytes = scanf("%[a-zA-Z0-9.! ]", buf);
	if (bytes != 0)
		printf("%s\n", buf);
	return (0);
}
