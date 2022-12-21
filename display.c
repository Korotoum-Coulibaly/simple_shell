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
		{
			free_all_data(data);
			exit(errno);
		}
		if (stringSize >= 1)
		{
			expand_alias(data);
			expand_variables(data);
			/*tokenize(data);
			if (data ->tokens[0])
			{
				error_code = execute(data);
				if (error_code != 0)
					_print_error(error_code, data);
			}
			*/
			free_recurrent_data(data);
		}

	}
}
