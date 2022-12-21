#include "header.h"

/**
 * env_get_key - value of an environnement variable
 * @key: the environnement variable of interest
 * @data: data structure
 *
 * Return: pointer to the value of the variable or NULL
 */
char *env_get_key(char *key, struct init_data *data)
{
	int i, key_length = 0;

	/*test argument*/
	if (key == NULL || data->env == NULL)
		return (NULL);
	/* obtains the leng of the variable requested */
	key_length = strlength(key);

	for (i = 0; data->env[i]; i++)
	{
		if (str_compare(key, data->env[i], key_length) && data->env[i][key_length] == '=')
		{
			return (data->env[i] + key_length + 1);
		}
	}
	return (NULL);
}
