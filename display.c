#include "header.h"

/**
 * display - Display a prompt and wait for the user to type a command
 * @prompt: prompt to be printed
 * @data: infinite loop that shows the prompt
 */
void display(char *prompt, struct init_data *data)
{
	int error_code = 0;
	int stringSize = 0;

	while (++(data->exec_counter))
	{
		_print(prompt);
		error_code = stringSize = _getline(data);

		if (error_code == EOF)
			printf("okay");
	}
}
