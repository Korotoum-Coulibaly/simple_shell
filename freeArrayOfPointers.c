#include "header.h"

/**
 * free_array_of_pointers - free each pointer of an array
 * @array: array of pointers
 */
void free_array_of_pointers(char **array)
{
	int i;

	if (array != NULL)
	{
		for (i = 0; array[i]; i++)
			free(array[i]);
		free(array);
		array = NULL;
	}
}
