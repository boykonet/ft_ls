#include "../ls.h"

static void	swap(void **first, void **second)
{
	char *tmp;

	tmp = *first;
	*first = *second;
	*second = tmp;
}

int		order_cmp_by_filename(t_fileinfo *first, t_fileinfo *second, int is_inverted)
{
	int 	flen, slen;
	int 	res;

	flen = ft_strlen(first->filename);
	slen = ft_strlen(second->filename);
	res = ft_memcmp(first->filename, second->filename, flen > slen ? flen: slen);
	return (is_inverted == FLAG_INVERTED_NO) ? (res > 0) : (res < 0);
}

int		order_cmp_by_tlastmod(t_fileinfo *first, t_fileinfo *second, int is_inverted)
{
	return (is_inverted == FLAG_INVERTED_NO ? (first->mtime.tv_sec < second->mtime.tv_sec) : (first->mtime.tv_sec > second->mtime.tv_sec));
}

void	sort_fileinfo(t_fileinfo ***array, int (*func)(t_fileinfo*, t_fileinfo*, int), int is_inverted)
{
	t_fileinfo	**p;
	size_t		i, j, len;

	if (!array)
		return ;
	p = *array;
	len = len_2array((const void**)p);
	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (func(p[i], p[j], is_inverted))
				swap((void**)&p[i], (void**)&p[j]);
			j++;
		}
		i++;
	}
}
