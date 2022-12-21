#include "header.h"

/**
 * _print - array of chars for standard output
 * @string: information
 *
 * Return: size of string or -1 for error
 */
int _print(char *string)
{
	return (write(STDOUT_FILENO, string, strlength(string)));
}
