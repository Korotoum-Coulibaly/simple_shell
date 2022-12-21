#ifndef _HEADER_H_
#define _HEADER_H_

#include <stdio.h>
/**
 * Unistd.h header defines miscellaneous symbolic constants
 * and types, and declares miscellaneous functions. The contents
 * of this header are shown below.
 */
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
/**
 * signal allows us to add the interrupt signal CTRL+c
 */
#include <signal.h>
/**
 * error management
 */
#include <errno.h>
/**
 *For use Open function...
 */
#include <fcntl.h>
/**
 *Constant or macro
 */
#include "macros.h"

/**
  * struct info- struct for the program's data
  * @program_name: the name of the executable
  * @input_line: pointer to the input read for _getline
  * @command_name: pointer to the first command typed by the user
  * @exec_counter: number of excecuted commands
  * @file_descriptor: file descriptor to the input of commands
  * @tokens: pointer to array of tokenized input
  * @env: copy of the environ
  * @alias_list: array of pointers with aliases.
  */

struct init_data
{
	char *program_name;
	char *input_line;
	char *command_name;
	int exec_counter;
	/*
	 * Each command is associated with a descriptor file
	 */
	int file_descriptor;
	/*
	 * Processus Id
	 */
	char **tokens;
	/*
	 * Environment
	 */
	char **env;
	/*
	 * We have seen in the previous courses, the allias,
	 * so it would be possible to have words associated
	 * with the basic command of the shell.
	 */
	char **alias_list;
	
};

/**Initialize data function**/
void initialize(struct init_data *data, int argc, char *argv[], char **env);

int _printAC(char *string);
int strlength(char *string);
char *_strcpy(char *string);


/* Makes the infinite loop that shows the prompt*/
void display(char *prompt, struct init_data *data);
int _print(char *string);
int _getline(struct init_data *data);
int check_logic_ops(char *array_commands[], int i, char array_operators[]);
char *_strtok(char *line, char *delim);

/* Memomry Management */
void free_all_data(struct init_data *data);
void free_recurrent_data(struct init_data *data);
void free_array_of_pointers(char **directories);

/* Expansion */
void expand_alias(struct init_data *data);
int buffer_add(char *buffer, char *str_to_add);
char *get_alias(struct init_data *data, char *name);
int str_compare(char *string1, char *string2, int number);

#endif /* _HEADER_H_ */
