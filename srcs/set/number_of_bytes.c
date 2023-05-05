/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   number_of_bytes.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: gkarina <gkarina@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/05 14:09:24 by gkarina       #+#    #+#                 */
/*   Updated: 2023/05/05 14:09:24 by gkarina       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../ls.h"

void	set_number_of_bytes(off_t st_size, char *bytes)
{
	if (bytes == NULL)
		return ;
	ft_bzero(bytes, sizeof(bytes));
	rec_itoa_ull(bytes, st_size, 10, DECIMAL_BASE_STR);
}
