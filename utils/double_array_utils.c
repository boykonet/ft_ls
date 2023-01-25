#include "../ls.h"

int len_double_char_array(char **darr)
{
	int len;

	len = 0;
	if (darr == NULL)
		return (0);
	while (darr[len] != NULL)
		len++;
	return len;
}

void	free_double_char_array(char **arr)
{
	int alen;

	alen = len_double_char_array(arr);
	if (alen == 0)
		return ;
	while (--alen >= 0)
	{
		if (arr[alen] != NULL)
		{
			free(arr[alen]);
			arr[alen] = NULL;
		}
	}
	free(arr);
	arr = NULL;
}

