/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   group.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: gkarina <gkarina@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/05 14:09:15 by gkarina       #+#    #+#                 */
/*   Updated: 2023/05/05 14:09:15 by gkarina       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../ls.h"

void	set_group(char group[STRING_SIZE + 1], gid_t st_gid)
{
	struct group	*grp;

	grp = getgrgid(st_gid);
	if (grp == NULL)
		rec_itoa_ull(group, st_gid, 10, DECIMAL_BASE_STR);
	else
		ft_strlcpy(group, grp->gr_name, STRING_SIZE);
}
