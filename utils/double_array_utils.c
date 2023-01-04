#include "utils.h"

int len_double_array(char **darray)
{
	int len;

	len = 0;
	if (darray == NULL)
		return (0);
	while (darray[len] != NULL)
		len++;
	return len;
}

void	free_double_array(char **array)
{
	int alen;

	alen = len_double_array(array);
	if (alen == 0)
		return ;
	while (--alen >= 0)
	{
		if (array[alen] != NULL)
			free(array[alen]);
	}
	free(array);
}