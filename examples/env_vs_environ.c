#include <stdio.h>

extern char **environ;

/**
 * main - compares printing the environment using environ vs the env argument
 * of the main function
 * @argc: number of arguments passed to main
 * @argv: pointer to array of pointers to strings that are arguments to main
 * @envp: pointer to array of pointers to strings that are the environment
 * variables
 *
 * Return: Always 0
 */
int main(int argc __attribute__((unused)), char **argv __attribute__((unused)), char **envp)
{
	unsigned int i;
	char **env = environ;

	printf("Using argument to main envp: \n");
	i = 0;
	while (envp[i])
	{
		printf("%s\n", envp[i]);
		i++;
	}

	printf("\nUsing the global variable environ\n");
	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
	return (0);
}
