#include "header.h"

/**
 * get_alias - add, remove or show alias
 * @data: data structure
 * @name: name of alias
 * Return: 0 success, or other number
 */
char *get_alias(struct init_data *data, char *name)
{
	int i, alias_size;
	/* validate the arguments */
	if (name == NULL || data->alias_list == NULL)
		return (NULL);

	alias_size = strlength(name);
	for (i = 0; data->alias_list[i]; i++)
	{
		if (str_compare(name, data->alias_list[i], alias_size) && data->alias_list[i][alias_size] == '=')
		{
			return (data->alias_list[i] + alias_size + 1);
		}
	}
	return (NULL);
}
