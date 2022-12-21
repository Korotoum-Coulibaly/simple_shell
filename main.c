#include "shell.h"

/**
  * main - initialize the variables of the program
  * @argc: number of values received from the command line
  * @argv: values received from the command line
  * @env: number of values received from the command line
  * Return: zero on succes.
  */

int main(int argc, char *argv[], char *env[])
{
	program_data data_struct = {NULL}, *data = &data_struct;
	char *prompt = "";

	inicialize_data(data, argc, argv, env);
	signal(SIGINT, handle_ctrl_c);
	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO) && argc == 1)
	{
		errno = 2;/*???????*/
		prompt = PROMPT_MSG;
	}
	errno = 0;
	sisifo(prompt, data);
	return (0);
}

/**
  * handle_ctrl_c - print the prompt in a new line
  * when the signal SIGINT (ctrl + c) is send to the program
  * @UNUSED: option of the prototype
  */
void handle_ctrl_c(int opr UNUSED)
{
	_print("\n");
	_print(PROMPT_MSG);
}

/**
  * inicialize_data - inicialize the struct with the info of the program
  * @data: pointer to the structure of data
  * @argv: array of arguments pased to the program execution
  * @env: environ pased to the program execution
  * @argc: number of values received from the command line
  */
void inicialize_data(data_of_program *data, int argc, char *argv[], char **env)
{
	int i = 0;

	data->program_name = argv[0];
	data->input_line = NULL;
	data->command_name = NULL;
	data->exec_counter = 0;
	/* define the file descriptor to be readed*/
	if (argc == 1)
		data->file_descriptor = STDIN_FILENO;
	else
	{
		data->file_descriptor = open(argv[1], O_RDONLY);
		if (data->file_descriptor == -1)
		{
			exit(127);
		}
	}
	data->tokens = NULL;
	data->env = malloc(sizeof(char *) * 50);
}
