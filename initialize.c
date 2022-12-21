#include "header.h"

/**
 * initialize - Function that init all information for shell
 * @data: information struc
 * @argc: number of values
 * @argv: parameters information
 * @env: array of number of values enter
 *
 * by Coulby
 */
void initialize(struct init_data *data, int argc, char *argv[], char **env)
{
	int i = 0;
	/**
	 * argv[0] always contains the name of the program and will
	 * allow us to manage the display of errors.
	 */
	data->program_name = argv[0];
	/**
	 * No entry in the black screen
	 */
	data->input_line = NULL;
	data->command_name = NULL;
	data->exec_counter = 0;
	/**
	 * To each created program a description file is associated,
	 * We can check if it exists with STDIN_fileno.
	 * 0 exist
	 * -1 error
	 */
	if (argc == 1)
		/**
		 * if the user has entered a single element,
		 * it is necessarily the name of the program,retrieves
		 * and searches the associated descriptor file
		 */
		data->file_descriptor = STDIN_FILENO;
	else
	{
		data->file_descriptor = open(argv[1], O_RDONLY);
		if (data->file_descriptor == -1)
		{
			_printAC(data->program_name);
			_printAC(": 0: Can't open ");
			_printAC(argv[1]);
			_printAC("\n");
			exit(127);
		}
	}
	data->tokens = NULL;
	/**
	 * On reserve 50 bytes
	 */
	data->env = malloc(sizeof(char *) * 50);

	if (env)
	{
		for (; env[i]; i++)
			data->env[i] = _strcpy(env[i]);
	}
	data->env[i] = NULL;
	env = data->env;

	data->alias_list = malloc(sizeof(char *) * 20);
	for (i = 0; i < 20; i++)
	{
		data->alias_list[i] = NULL;
	}

}