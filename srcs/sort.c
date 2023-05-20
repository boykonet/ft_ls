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

int		order_cmp_by_filename(void *first, void *second, unsigned short flags)
{
	char	*f;
	char	*s;
	int 	res;

	if (first == NULL || second == NULL)
		return (-2);
	f = ((t_fileinfo*)first)->filename;
	s = ((t_fileinfo*)second)->filename;
	res = ft_memcmp(f, s, max((int)ft_strlen(f), (int)ft_strlen(s)));
	return (is_flag(flags, R_FLAG) == 0) ? \
	res > 0 : \
	res < 0;
}

int		order_cmp_by_time(void *first, void *second, unsigned short flags)
{
	struct timespec f;
	struct timespec	s;

	if (first == NULL || second == NULL)
		return (-2);
//	if (is_flag(flags, U_FLAG) == 1 && is_flag(flags, T_FLAG) == 1)
//	{
//		f = ((t_fileinfo*)first)->atime;
//		s = ((t_fileinfo*)second)->atime;
//	}
//	else
//	{
	f = ((t_fileinfo*)first)->mtime;
	s = ((t_fileinfo*)second)->mtime;
//	}
	return (is_flag(flags, R_FLAG) == 0 ? \
	is_less_equal(f.tv_sec, s.tv_sec) : \
	is_more_equal(f.tv_sec, s.tv_sec));
}

void	sort_fileinfo(t_fileinfo **array, size_t count_elems, int (*func)(void*, void*, unsigned short), unsigned short flags)
{
	size_t		count;

	if (array == NULL)
		return ;
	count = len_2array((const void**)array);
	count = count > count_elems ? count_elems : count;
	quick_sort((void***)&array, count, func, flags);
}

void	sort_by_flags(t_fileinfo **files, unsigned short flags)
{
	size_t	i, j;
	size_t	flen;

	if (files == NULL)
		return ;
	if (is_flag(flags, F_FLAG) == 1)
		return ;
	if (is_flag(flags, T_FLAG) == 1)
	{
		sort_fileinfo(files, len_2array((const void **)files), order_cmp_by_time, flags);
		flen = len_2array((const void**)files);
		i = 0;
		while (i < flen)
		{
			j = 0;
//			if (is_flag(flags, U_FLAG) == 1)
//			{
//				while (i + j < flen && files[i]->atime.tv_sec == files[i + j]->atime.tv_sec)
//					j++;
//			}
//			else
//			{
			while (i + j < flen && files[i]->mtime.tv_sec == files[i + j]->mtime.tv_sec)
				j++;
//			}
			if (j > 1)
				sort_fileinfo(&files[i], j, order_cmp_by_filename, flags);
			i += j;
		}
	}
	else
		sort_fileinfo(files, len_2array((const void **)files), order_cmp_by_filename, flags);
}
