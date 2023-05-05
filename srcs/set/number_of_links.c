/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   number_of_links.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: gkarina <gkarina@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/05 14:09:27 by gkarina       #+#    #+#                 */
/*   Updated: 2023/05/05 14:09:27 by gkarina       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../ls.h"

void	set_number_of_links(nlink_t st_nlinks, char *links)
{
	if (links == NULL)
		return ;
	ft_bzero(links, sizeof(links));
	rec_itoa_ull(links, st_nlinks, 10, DECIMAL_BASE_STR);
}
