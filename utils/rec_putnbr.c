/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rec_putnbr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: gkarina <gkarina@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/05 14:23:38 by gkarina       #+#    #+#                 */
/*   Updated: 2023/05/05 14:23:38 by gkarina       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/libft/libft.h"

void	putnbr(long long number, int base, char *base_str)
{
	unsigned long long nn;

	nn = number;
	if (number < 0)
	{
		ft_putchar_fd('-', 1);
		nn = number * (-1);
	}
	if (nn >= (unsigned long long)base)
		putnbr(nn / base, base, base_str);
	ft_putchar_fd(base_str[nn % base], 1);
}
