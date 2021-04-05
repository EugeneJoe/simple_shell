#include <unistd.h>
#include <sys/types.h> 
#include <stdio.h>

/**
 * main - PID of this process and the parent process
 *
 * Return: Always 0
 */
int main(void)
{
	pid_t my_pid, p_pid;

	my_pid = getpid();
	p_pid = getppid();
	printf("my_pid = %u\n", my_pid);
	printf("p_pid = %u\n", p_pid);
	return (0);
}
