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

void	free_2array_content(void **arr)
{
	size_t	asize, i;

	if (arr == NULL)
		return ;
	asize = sizeof(arr);
	i = 0;
	while (asize / sizeof(void*) > i)
	{
		if (arr[i] != NULL)
		{
			free(arr[i]);
			arr[i] = NULL;
		}
		i++;
	}
}

void	free_2array(void **arr)
{
	free_2array_content(arr);
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
	int		ecode;
	size_t	len;

	len = 0;
	ecode = 0;
	if (data == NULL || value == NULL)
		return (-2);
	if (*data == NULL)
	{
		*data = (void**)ft_calloc(2, sizeof(void*));
		if (*data == NULL)
			ecode = -1;
	}
	else
	{
		len = len_2array((const void **)(*data));
		ecode = realloc_2array(data, len + 1);
	}
	if (ecode != 0)
		return (ecode);
	(*data)[len] = value;
	return (0);
}
