#include "../ls.h"

int len_2_pointer_array(const void **darr)
{
	int len;

	len = 0;
	if (darr == NULL)
		return (0);
	while (darr[len] != NULL)
		len++;
	return len;
}

void	free_2_pointer_array(void **arr)
{
	int alen;

	alen = len_2_pointer_array((const void**)arr);
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

