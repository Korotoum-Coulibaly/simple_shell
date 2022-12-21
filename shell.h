#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
#include <fcntl.h>

#include "macros.h"

/**
  * struct info- struct for the program's data
  * @program_name: the name of the executable
  * @input_line: pointer to the input read for _getline
  * @command_name: pointer to the first command typed by the user
  * @exec_counter: number of excecuted comands
  * @file_descriptor: file descriptor to the input of commands
  * @tokens: pointer to array of tokenized input
  * @env: copy of the environ
  * @alias_list: array of pointers with aliases.
  */

typedef struct info
{
	char *program_name;
	char *input_line;
	char *command_name;
	int exec_counter;
	int file_descriptor;
	char **tokens;
	char **env;
	char **alias_list;
} program_data;

/************* MAIN FUNCTIONS *************/


/*========  shell.c  ========*/

/* Inicialize the struct with the info of the program */
void inicialize_data(program_data *data, int arc, char *argv[], char **env);

/* Makes the infinite loop that shows the prompt*/
void sisifo(char *prompt, program_data *data);

/* Print the prompt in a new line */
void handle_ctrl_c(int opr UNUSED);

#endif
