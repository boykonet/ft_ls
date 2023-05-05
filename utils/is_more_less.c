/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_more_less.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: gkarina <gkarina@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/05 14:23:07 by gkarina       #+#    #+#                 */
/*   Updated: 2023/05/05 14:23:07 by gkarina       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ls.h"

int 	is_more_equal(long first, long second)
{
	return (first >= second);
}

int		is_less_equal(long first, long second)
{
	return (first <= second);
}
