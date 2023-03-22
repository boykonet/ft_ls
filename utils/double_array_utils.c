#include "../ls.h"

int len_2array(const void **darr)
{
	int len;

	len = 0;
	if (darr == NULL)
		return (0);
	while (darr[len] != NULL)
		len++;
	return len;
}

void	free_2array(void **arr)
{
	int alen;

	alen = len_2array((const void **) arr);
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

int		realloc_2array(void ***data, size_t size)
{
	void	**p;
	void	**res;
	size_t	i;

	if (!data)
		return (-2);
	p = *data;
	res = (void**)ft_calloc(size + 1, sizeof(void*));
	if (!res)
		return (-1);
	i = 0;
	while (p && p[i] != NULL)
	{
		res[i] = p[i];
		i++;
	}
	free(*data);
	*data = res;
	return (0);
}

int	add_2array(void ***data, void *value)
{
	int		e;
	size_t	len;

	if (data == NULL || value == NULL)
		return (-2);
	len = len_2array((const void**)(*data));
	e = realloc_2array(data, len + 1);
	if (e != 0)
		return (e);
	(*data)[len] = value;
	return (0);
}
