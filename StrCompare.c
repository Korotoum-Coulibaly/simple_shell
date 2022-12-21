#include "header.h"

/**
 * str_compare - compare two strings
 * @string1: string one
 * @string2: string two
 * @number: number of charactères to be compared
 *
 * Return: 1
 */
int str_compare(char *string1, char *string2, int number)
{
	int iterator;

	if (string1 == NULL && string2 == NULL)
		return (1);
	if (string1 == NULL || string2 == NULL)
		return (0);
	if (number == 0)
	{
		if (strlength(string1) != strlength(string2))
			return (0);
		for (iterator = 0; string1[iterator]; iterator++)
		{
			if (string1[iterator] != string2[iterator])
				return (0);
		}
		return (1);
	}
	else
	{
		for (iterator = 0; iterator < number ; iterator++)
		{
			if (string1[iterator] != string2[iterator])
				return (0);
		}
		return (1);
	}
}
