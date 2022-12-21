#include "header.h"

/**
 * free_all_data - free all field of the data
 * @data: data structure
 */
void free_all_data(struct init_data *data)
{
	if (data->file_descriptor != 0)
	{
		if (close(data->file_descriptor))
			perror(data->program_name);
	}
	free_recurrent_data(data);
	free_array_of_pointers(data->env);
	free_array_of_pointers(data->alias_list);
}
