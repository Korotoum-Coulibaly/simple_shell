#include "header.h"

/**
 * strlength - size of string
 * @string: information
 *
 * Return: size of string
 */
int strlength(char *string)
{
	int length = 0;

	if (string == NULL)
		return (0);
	while (string[length++] != '\0')
	{
	}
	return (--length);
}
