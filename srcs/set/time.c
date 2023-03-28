#include "../../ls.h"

void	set_time(struct timespec st_mtimespec, char *amonth, char *day_lm, char *time_year_lm, struct timespec *mtime)
{
	char	**t;
	time_t	sts;
	long	diff;

	mtime->tv_sec = st_mtimespec.tv_sec;
	mtime->tv_nsec = st_mtimespec.tv_nsec;

	t = ft_split(ctime((const time_t*)&st_mtimespec.tv_sec), ' ');
	if (!t)
	{
		perror("malloc");
		exit(1);
	}

	ft_memcpy(amonth, t[1], ft_strlen(t[1]));
	ft_memcpy(day_lm, t[2], ft_strlen(t[2]));

	// get current time
	sts = time(NULL);
	if (sts == -1)
	{
		perror("time");
		exit(1);
	}
	diff = sts - (const time_t)st_mtimespec.tv_sec;
	if (diff >= 0 && diff < HALF_OF_YEAR_SECONDS)
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
}