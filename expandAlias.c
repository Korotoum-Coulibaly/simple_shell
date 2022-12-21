#include "header.h"

/**
 * expand_alias - save alias
 * @data: data structure
 */
void expand_alias(struct init_data *data)
{
	int i, j, expand = 0;
	char line[BUFFER_SIZE] = {0};
	char expansion[BUFFER_SIZE] = {'\0'}, *temp;

	if (data->input_line == NULL)
		return;
	buffer_add(line, data->input_line);

	for (i = 0; line[i]; i++)
	{
		for (j = 0; line[i + j] && line[i + j] != ' '; j++)
			expansion[j] = line[i + j];
		expansion[j] = '\0';

		temp = get_alias(data, expansion);
		if (temp)
		{
			expansion[0] = '\0';
			buffer_add(expansion, line + i + j);
			line[i] = '\0';
			buffer_add(line, temp);
			line[strlength(line)] = '\0';
			buffer_add(line, expansion);
			expand = 1;
		}
		break;
	}
	if (expand)
	{
		free(data->input_line);
		data->input_line = _strcpy(line);
	}
}
