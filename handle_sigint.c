#include "shellheader.h"

/**
 * handle_sigint - handles the SIGINT signal (caused by Ctrl-C at the keyboard)
 * @sig: signal passed
 *
 * Return: no return value (void)
 */
void handle_sigint(int sig __attribute__((unused)))
{
	write(STDOUT_FILENO, "\n", 1);
	write(STDOUT_FILENO, "$ ", 3);
}
