#include "../ls.h"

void	ispaces(t_spaces *spaces)
{
	spaces->s_link = 0;
	spaces->s_oname = 0;
	spaces->s_gname = 0;
	spaces->s_bytes = 0;
	spaces->s_day = 0;
	spaces->s_time_year = 0;
}

void	set_spaces(char spaces[LONG_FORNAT_PARRERN_MAXS][254 + 1], t_fileinfo *finfo, t_spaces maxs)
{
	size_t	cos[LONG_FORNAT_PARRERN_MAXS]; // count of spaces
	size_t	i;

	ft_bzero(cos, sizeof(size_t) * LONG_FORNAT_PARRERN_MAXS);
	cos[0] = maxs.s_link - ft_strlen(finfo->nlinks);
	cos[1] = maxs.s_oname - ft_strlen(finfo->oname);
	cos[2] = maxs.s_gname - ft_strlen(finfo->gname);
	cos[3] = maxs.s_bytes - ft_strlen(finfo->nbytes);
	cos[4] = maxs.s_day - ft_strlen(finfo->day_lm);
	cos[5] = maxs.s_time_year - ft_strlen(finfo->time_year_lm);

	i = 0;
	while (i < LONG_FORNAT_PARRERN_MAXS)
	{
		ft_memset(spaces[i], ' ', cos[i]);
		i++;
	}
}

void	counter_of_spaces(t_fileinfo **info, t_spaces *spaces)
{
	if (info == NULL || spaces == NULL)
		return ;
	for (size_t i = 0; info[i]; i++)
	{
		max_spaces(&spaces->s_link, ft_strlen(info[i]->nlinks));
		max_spaces(&spaces->s_oname, ft_strlen(info[i]->oname));
		max_spaces(&spaces->s_gname, ft_strlen(info[i]->gname));
		max_spaces(&spaces->s_bytes, ft_strlen(info[i]->nbytes));
		max_spaces(&spaces->s_day, ft_strlen(info[i]->day_lm));
		max_spaces(&spaces->s_time_year, ft_strlen(info[i]->time_year_lm));
	}
}
