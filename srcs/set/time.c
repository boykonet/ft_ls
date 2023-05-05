/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   time.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: gkarina <gkarina@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/05 14:09:34 by gkarina       #+#    #+#                 */
/*   Updated: 2023/05/05 14:09:34 by gkarina       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../ls.h"

int	set_time(struct timespec st_time, char *amonth, char *day_lm, char *time_year_lm)
{
	char	**t;
	time_t	sts;
	long	diff;

	t = ft_split(ctime((const time_t*)&st_time.tv_sec), ' ');
	if (!t)
		return (ERR_CODE_MALLOC_ERROR);

	ft_memcpy(amonth, t[1], ft_strlen(t[1]));
	ft_memcpy(day_lm, t[2], ft_strlen(t[2]));

	/* get current time */
	sts = time(NULL);
	if (sts == -1)
	{
		free_2array((void **)t);
		t = NULL;
		return (ERR_CODE_STRERROR);
	}
	diff = sts - (const time_t)st_time.tv_sec;
	if (diff >= 0 && (double)diff < HALF_OF_YEAR_SECONDS)
	{
		*ft_strrchr(t[3], ':') = '\0';
		ft_memcpy(time_year_lm, t[3], ft_strlen(t[3]));
	}
	else
	{
		*ft_strrchr(t[4], '\n') = '\0';
		ft_memcpy(time_year_lm, t[4], ft_strlen(t[4]));
	}
	free_2array((void**)t);
	t = NULL;
	return (0);
}
