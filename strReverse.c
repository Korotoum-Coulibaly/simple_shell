#include "header.h"

/**
 * str_reverse - reverse string
 * @string: pointer to string
 */
void str_reverse(char *string)
{
	int i = 0;
	int size = strlength(string) - 1;
	char hold;

	while (i < size)
	{
		hold = string[i];
		string[i++] = string[size];
		string[size--] = hold;
	}
}
