/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   filetype.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: gkarina <gkarina@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/05 14:09:10 by gkarina       #+#    #+#                 */
/*   Updated: 2023/05/05 14:09:10 by gkarina       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../ls.h"

void	set_type(unsigned int *type, mode_t st_mode)
{
	if (type == NULL)
		return ;
	*type = (unsigned int)(st_mode & S_IFMT);
}
