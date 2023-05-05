/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   link.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: gkarina <gkarina@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/05 14:09:21 by gkarina       #+#    #+#                 */
/*   Updated: 2023/05/05 14:09:21 by gkarina       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../ls.h"

int	set_link(const char *filepath, char *link)
{
	int	ecode;

	if (filepath == NULL)
		return (ERR_CODE_NULL_PARAMETER);
	ecode = creadlink(filepath, link);
	if (ecode != 0)
		return (ecode);
	return (0);
}
