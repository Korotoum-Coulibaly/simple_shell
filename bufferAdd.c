#include "header.h"

/**
 * buffer_add - Append string at end of the buffer
 * @buffer: buffer to be filled
 * @str_to_add: string to be copied
 */
int buffer_add(char *buffer, char *str_to_add)
{
	int size, i;

	size = strlength(buffer);
	for(i = 0; str_to_add[i]; i++)
	{
		buffer[size + i] = str_to_add[i];
	}
	buffer[size + i] = '\0';
	return (size + i);
}
