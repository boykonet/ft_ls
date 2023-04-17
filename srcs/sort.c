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
	res > 0 : \
	res < 0;
}

int		order_cmp_by_tlastmod(t_fileinfo *first, t_fileinfo *second, int is_inverted)
{
	return (is_inverted == FLAG_INVERTED_NO ? \
	is_less_equal(first->mtime.tv_sec, second->mtime.tv_sec) : \
	is_more_equal(first->mtime.tv_sec, second->mtime.tv_sec));
}

void	sort_fileinfo(t_fileinfo **array, size_t count_elems, int (*func)(t_fileinfo*, t_fileinfo*, int), int is_inverted)
{
	size_t		i, j, len;

	if (array == NULL)
		return ;
	len = len_2array((const void**)array);
	len = len > count_elems ? count_elems : len;
	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (func(array[i], array[j], is_inverted))
				swap((void**)&array[i], (void**)&array[j]);
			j++;
		}
		i++;
	}
}

void	sort_by_flags(t_fileinfo **files, unsigned char flags)
{
	size_t		i, j;

	if (files == NULL)
		return ;

	if (is_flag(flags, T_FLAG_SHIFT, T_FLAG_NUM) == 0)
		sort_fileinfo(files, len_2array((const void **)files), order_cmp_by_filename, is_flag(flags, R_FLAG_SHIFT, R_FLAG_NUM));
	if (is_flag(flags, T_FLAG_SHIFT, T_FLAG_NUM) == 1)
	{
		sort_fileinfo(files, len_2array((const void **)files), order_cmp_by_tlastmod, is_flag(flags, R_FLAG_SHIFT, R_FLAG_NUM));

		size_t	flen = len_2array((const void**)files);

//		for (size_t k = 0; k < flen; k++)
//			printf("file [%10s], index [%2.zu], time last modified [%10.ld]\n", files[k]->filename, k, files[k]->mtime.tv_sec);


		i = 0;
		while (i < flen)
		{
			j = 0;
			while (i + j < flen && files[i]->mtime.tv_sec == files[i + j]->mtime.tv_sec)
				j++;
//			printf("i = [%zu] j = [%zu], count elems [%zu]\n", i, i + j, j);
////			printf("REVERSE FLAG [%d], j = [%zu]\n", is_flag(flags, R_FLAG_SHIFT, R_FLAG_NUM), j);
////			if (j - i > 1)
////			{
////				printf("JJJJJJJ [%zu]\n", j);
////				printf("FIRST [%s %s %s], SECOND [%s %s %s]\n", files[i]->amonth, files[i]->day_lm, files[i]->time_year_lm, files[j - 1]->amonth, files[j - 1]->day_lm, files[j - 1]->time_year_lm);
			if (j > 1)
				sort_fileinfo(&files[i], j, order_cmp_by_filename, is_flag(flags, R_FLAG_SHIFT, R_FLAG_NUM));
			i += j;
		}
	}
}
