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

int		add_value_2array(char ***data, const char *value)
{
	char	**p;
	char	**res;
	size_t	size;

	if (!data || !value)
		return (-2);
	p = *data;
	size = len_2array((const void**)p);
	res = (char**)calloca_to_2d(size + 1 + 1);
	if (!res)
		return (-1);
	size_t	i = 0;
	while (p)
	{
		res[i] = *p;
		p++;
		i++;
	}
	res[i] = ft_strdup(value);
	if (!res[i])
	{
		free(res);
		return (-1);
	}
	free_2array((void**)*data);
	*data = res;
	return (0);
}
