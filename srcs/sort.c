/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: gkarina <gkarina@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/05 14:20:49 by gkarina       #+#    #+#                 */
/*   Updated: 2023/05/05 14:20:49 by gkarina       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

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
	is_less_equal(f->filetime.tv_sec, s->filetime.tv_sec) : \
	is_more_equal(f->filetime.tv_sec, s->filetime.tv_sec));
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

void	sort_by_flags(t_fileinfo **files, unsigned short flags)
{
	size_t	i, j;
	size_t	flen;

	if (files == NULL)
		return ;
	if (is_flag(flags, F_FLAG_SHIFT, F_FLAG_VALUE) == 1)
		return ;
	if (is_flag(flags, T_FLAG_SHIFT, T_FLAG_VALUE) == 0)
		sort_fileinfo(files, len_2array((const void **)files), order_cmp_by_filename, is_flag(flags, R_FLAG_SHIFT, R_FLAG_VALUE));
	if (is_flag(flags, T_FLAG_SHIFT, T_FLAG_VALUE) == 1)
	{
		sort_fileinfo(files, len_2array((const void **)files), order_cmp_by_tlastmod, is_flag(flags, R_FLAG_SHIFT, R_FLAG_VALUE));
		flen = len_2array((const void**)files);
		i = 0;
		while (i < flen)
		{
			j = 0;
			while (i + j < flen && files[i]->filetime.tv_sec == files[i + j]->filetime.tv_sec)
				j++;
			if (j > 1)
				sort_fileinfo(&files[i], j, order_cmp_by_filename, is_flag(flags, R_FLAG_SHIFT, R_FLAG_VALUE));
			i += j;
		}
	}
}
