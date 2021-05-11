#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

/**
 * main - a simple shell that can run commands with their full path, without
 * any arguments
 *
 * Return: Always 0
 */
int main(void)
{
	char *command;
	int status, child_pid;
	ssize_t bytes;
	size_t nn;
	char *args[] = {NULL};

	while (1)
	{
		printf("#JOE_SHELL$ ");
		bytes = getline(&command, &nn, stdin);
		if (bytes != 0)
		{
			if (strcmp(command, "^C") == 0)
				break;
			child_pid = fork();
			if (child_pid == -1)
			{
				perror("Error: ");
				return (1);
			}
			if (child_pid == 0)
			{
				if (execve(command, args, NULL) == -1)
					perror("Error: ");
			}
			else
			{
				wait(&status);
				bytes = 0;
			}
		}
		else
		{
			perror("Error: ");
		}
	}
	return (0);
}
