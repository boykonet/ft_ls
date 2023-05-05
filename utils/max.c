/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   max.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: gkarina <gkarina@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/05 14:23:10 by gkarina       #+#    #+#                 */
/*   Updated: 2023/05/05 14:23:10 by gkarina       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		max(int first, int second)
{
	return (first > second ? first : second);
}

void	max_spaces(size_t *first, size_t second)
{
	if (first == NULL)
		return ;
	if (*first < second)
		*first = second;
}
