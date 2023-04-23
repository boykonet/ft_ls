#include "../ls.h"

int		order_cmp_by_filename(void *first, void *second, int is_inverted)
{
	t_fileinfo	*f;
	t_fileinfo	*s;
	int 	res;

	if (first == NULL || second == NULL)
		return (-2);
	f = (t_fileinfo*)first;
	s = (t_fileinfo*)second;
	res = ft_memcmp(f->filename, s->filename, \
	max((int)ft_strlen(f->filename), (int)ft_strlen(s->filename)));
	return (is_inverted == FLAG_INVERTED_NO) ? \
	res > 0 : \
	res < 0;
}

int		order_cmp_by_tlastmod(void *first, void *second, int is_inverted)
{
	t_fileinfo	*f;
	t_fileinfo	*s;

	if (first == NULL || second == NULL)
		return (-2);
	f = (t_fileinfo*)first;
	s = (t_fileinfo*)second;
	return (is_inverted == FLAG_INVERTED_NO ? \
	is_less_equal(f->mtime.tv_sec, s->mtime.tv_sec) : \
	is_more_equal(f->mtime.tv_sec, s->mtime.tv_sec));
}

void	sort_fileinfo(t_fileinfo **array, size_t count_elems, int (*func)(void*, void*, int), int is_inverted)
{
	size_t		/*i, j, */count;

	if (array == NULL)
		return ;
	count = len_2array((const void**)array);
	count = count > count_elems ? count_elems : count;
	quick_sort((void***)&array, count, func, is_inverted);
}

void	sort_by_flags(t_fileinfo **files, unsigned char flags)
{
	size_t	i, j;
	size_t	flen;

	if (files == NULL)
		return ;

	if (is_flag(flags, T_FLAG_SHIFT, T_FLAG_NUM) == 0)
		sort_fileinfo(files, len_2array((const void **)files), order_cmp_by_filename, is_flag(flags, R_FLAG_SHIFT, R_FLAG_NUM));
	if (is_flag(flags, T_FLAG_SHIFT, T_FLAG_NUM) == 1)
	{
		sort_fileinfo(files, len_2array((const void **)files), order_cmp_by_tlastmod, is_flag(flags, R_FLAG_SHIFT, R_FLAG_NUM));
		flen = len_2array((const void**)files);
		i = 0;
		while (i < flen)
		{
			j = 0;
			while (i + j < flen && files[i]->mtime.tv_sec == files[i + j]->mtime.tv_sec)
				j++;
			if (j > 1)
				sort_fileinfo(&files[i], j, order_cmp_by_filename, is_flag(flags, R_FLAG_SHIFT, R_FLAG_NUM));
			i += j;
		}
	}
}
