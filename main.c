#include "header.h"

/**
 * main - Principal function that start the program
 * Three parameters,
 * @argc: Number of values enter
 * @argv: parameters enter value 
 * @env: Create array of pointer to store all number of values enter
 *
 * Return: Always 0 for success
 * @Coulby
 */
int main (int argc, char *argv[], char *env[])
{
	/**
	 *Create a variable that will retrieve initialize information
	 * For that, we have create struct init_data
	 */

	struct init_data  data_information = {NULL};
	struct init_data *data = &data_information;

	/**
	 *Prompt corresponds to the variable that has the shell
	 *keyword in it, but at the beginning for an initialization
	 *we simulate a black screen by putting prompt = "".
	 */
	char *prompt = "";

	/**
	 *The initialization is long so we will create a file init.c
	 *which contains the initialization function, we will then
	 *call it in the header.
	 */
	initialize(data, argc, argv, env);

	/**********Display a prompt*******/

	/*isatty is in the book unistd.h*/
	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO) && argc == 1)
	{
		/*call error.h*/
		errno = 2;
		prompt = "$";
	}
	
	errno = 0;
	display(prompt, data);
	
	return (0);
}
