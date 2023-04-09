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
	int 	res;

	res = ft_memcmp(first->filename, second->filename, \
	max((int)ft_strlen(first->filename), (int)ft_strlen(second->filename)));
	return (is_inverted == FLAG_INVERTED_NO) ? \
	is_more(res, 0) : \
	is_less(res, 0);
}

int		order_cmp_by_tlastmod(t_fileinfo *first, t_fileinfo *second, int is_inverted)
{
	return (is_inverted == FLAG_INVERTED_NO ? \
	is_less(first->mtime.tv_sec, second->mtime.tv_sec) : \
	is_more(first->mtime.tv_sec, second->mtime.tv_sec));
}

void	sort_fileinfo(t_fileinfo **array, size_t count_elems, int (*func)(t_fileinfo*, t_fileinfo*, int), int is_inverted)
{
	t_fileinfo	**p;
	size_t		i, j, len;

	if (array == NULL)
		return ;
	p = array;
	len = len_2array((const void**)p);
	len = len < count_elems ? len : count_elems;
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

int		is_date_equal(t_fileinfo *first, t_fileinfo *second)
{
	if (first == NULL || second == NULL)
		return (-2);
	if (ft_strncmp(first->amonth, second->amonth, 3) == 0 \
	&& ft_strncmp(first->day_lm, second->day_lm, 2) == 0 \
	&& ft_strncmp(first->time_year_lm, second->time_year_lm, 5) == 0)
		return (1);
	return (0);
}

void	sort_by_flags(t_fileinfo **files, unsigned char flags)
{
	size_t		i;

	if (files == NULL)
		return ;

	if (is_flag(flags, T_FLAG_SHIFT, T_FLAG_NUM) == 1)
	{
		sort_fileinfo(files, len_2array((const void **)files), order_cmp_by_tlastmod, is_flag(flags, R_FLAG_SHIFT, R_FLAG_NUM));
		i = 0;
		size_t	flen = len_2array((const void**)files);
		while (i < flen)
		{
			size_t j = i + 1;
			while (j < flen && is_date_equal(files[i], files[j]) == 1)
				j++;
			if (j - i > 1)
				sort_fileinfo(&files[i], j - i, order_cmp_by_filename, is_flag(flags, R_FLAG_SHIFT, R_FLAG_NUM));
			i += j;
		}
	}
}
