/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flag.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: gkarina <gkarina@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/20 22:17:15 by gkarina       #+#    #+#                 */
/*   Updated: 2023/05/20 22:17:15 by gkarina       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ls.h"

static void	set_shift_value(char flag, int *shift, int *value)
{
	size_t	i;
	t_flags f[MAX_FLAGS + 1] = {
			{.flag = COLOR_FLAG, .shift = COLOR_FLAG_SHIFT, .value = COLOR_FLAG_VALUE},
			{.flag = REC_FLAG, .shift = REC_FLAG_SHIFT, .value = REC_FLAG_VALUE},
			{.flag = A_FLAG, .shift = A_FLAG_SHIFT, .value = A_FLAG_VALUE},
			{.flag = L_FLAG, .shift = L_FLAG_SHIFT, .value = L_FLAG_VALUE},
			{.flag = R_FLAG, .shift = R_FLAG_SHIFT, .value = R_FLAG_VALUE},
			{.flag = T_FLAG, .shift = T_FLAG_SHIFT, .value = T_FLAG_VALUE},
			{.flag = D_FLAG, .shift = D_FLAG_SHIFT, .value = D_FLAG_VALUE},
			{.flag = F_FLAG, .shift = F_FLAG_SHIFT, .value = F_FLAG_VALUE},
			{.flag = G_FLAG, .shift = G_FLAG_SHIFT, .value = G_FLAG_VALUE}};

	i = 0;
	if (shift == NULL || value == NULL)
		return ;
	while (i < MAX_FLAGS)
	{
		if (f[i].flag == flag)
		{
			*shift = f[i].shift;
			*value = f[i].value;
			return ;
		}
		i++;
	}
}

static void	set_flag(unsigned short *flags, char flag)
{
	int	shift;
	int value;

	shift = -1;
	value = -1;
	set_shift_value(flag, &shift, &value);
	if (((*flags) & (1 << shift)) != value)
		(*flags) |= (1 << shift);
}

int		is_flag(unsigned short flags, char flag)
{
	int	shift;
	int	value;

	shift = -1;
	value = -1;
	set_shift_value(flag, &shift, &value);
	if ((flags & (1 << shift)) == value)
		return (1);
	return (0);
}

int	add_flag(unsigned short *flags, char nf)
{
	int		shift;
	int		value;

	if (flags == NULL)
		return (-2);
	shift = -1;
	value = -1;
	set_shift_value(nf, &shift, &value);
	if (shift == -1 || value == -1)
		return (-1);
	set_flag(flags, nf);
	return (0);
}
