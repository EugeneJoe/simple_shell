#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - Executes the command "ls -l /tmp" in 5 different child processes
 *
 * Return: Always 0
 */
int main(void)
{
	char *argv[] = {"/bin/ls", "-l", "/printf", NULL};
	int status, child_pid, i;

	i = 0;
	while (i < 5)
	{
		printf("Before fork %d\n", i + 1);
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error: ");
			return (1);
		}
		if (child_pid == 0)
		{
			if(execve(argv[0], argv, NULL) == -1)
				perror("Error: ");
		}
		else
		{
			wait(&status);
			printf("Process %d complete\n", i + 1);
		}
		i++;
	}
	return (0);
}
