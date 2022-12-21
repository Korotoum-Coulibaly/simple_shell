#include "header.h"

/**
 *_getline - read one line from the prompt
 *@data: data structure
 *
 * Return: reading counting bytes
 */
int _getline(struct init_data *data)
{
	/**
	 * i have many difficult to write this code, 
	 * but one people help me
	 */
	char buff[BUFFER_SIZE] = {'\0'};
	static char *array_commands[10] = {NULL};
	static char array_operators[10] = {'\0'};
	ssize_t bytes_read, i = 0;
	
	/* check if doesnot exist more commands in the array */
	/* and checks the logical operators */
	if (!array_commands[0] || (array_operators[0] == '&' && errno != 0) || (array_operators[0] == '|' && errno == 0))
	{
		/*free the memory allocated in the array if it exists */
		for (i = 0; array_commands[i]; i++)
		{
			free(array_commands[i]);
			array_commands[i] = NULL;
		}

		/* read from the file descriptor int to buff */
		bytes_read = read(data->file_descriptor, &buff, BUFFER_SIZE - 1);
		if (bytes_read == 0)
			return (-1);
		/* split lines for \n or ; */
		i = 0;
		do {
			array_commands[i] = _strcpy(_strtok(i ? NULL : buff, "\n;"));
			/*checks and split for && and || operators*/
			i = check_logic_ops(array_commands, i, array_operators);
		} while (array_commands[i++]);
	}
	/*obtains the next command (command 0) and remove it for the array*/
	data->input_line = array_commands[0];
	for (i = 0; array_commands[i]; i++)
	{
		array_commands[i] = array_commands[i + 1];
		array_operators[i] = array_operators[i + 1];
	}
	return (strlength(data->input_line));
}
