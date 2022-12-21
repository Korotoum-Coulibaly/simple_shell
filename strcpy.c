#include "header.h"

/**
 * strcpy - copies string
 * @string: information to be copied
 *
 * Return: pointer to the array that contains string copies
 */
char *_strcpy(char *string)
{
	char *value;
	int size, i;

	if (string == NULL)
		return (NULL);

	size = strlength(string) + 1;
	value = malloc(sizeof(char) * size);

	if (value == NULL)
	{
		errno = ENOMEM;
		/**
		 *change the error message with perror
		 */
		 perror("Error");
		 return (NULL);
	}
	for (i = 0; i < size ; i++)
	{
		value[i] = string[i];
	}

	return (value);
}
