/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   isatty.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: gkarina <gkarina@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/05 16:23:56 by gkarina       #+#    #+#                 */
/*   Updated: 2023/05/05 16:23:56 by gkarina       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ls.h"

int	cisatty(int fd)
{
	struct termios	term;

	return (tcgetattr(fd, &term) == 0);
}
