#include "shell.h"

/**
 * myprint - Print a string to standard output.
 * @msg: The string to print.
 *
 * Return: void.
 */
void myprint(char *msg)
{
	write(STDOUT_FILENO, msg, _strlen(msg));
}

