#include "header.h"

/**
 * _printAC - array of chars contain standard error
 * @string: pointer of array
 * 
 * Return: size of string enter or -1 for error
 */
int _printAC(char *string)
{
	return (write(STDERR_FILENO, string, strlength(string)));
}
