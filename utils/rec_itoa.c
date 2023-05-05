/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rec_itoa.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: gkarina <gkarina@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/05 14:23:30 by gkarina       #+#    #+#                 */
/*   Updated: 2023/05/05 14:23:30 by gkarina       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ls.h"

int		count_of_ull(unsigned long long number, int base)
{
	int	count;

	count = 0;
	if (number == 0)
		return (1);
	while (number != 0)
	{
		number = number / base;
		count++;
	}
	return (count);
}

void	rec_itoa_ull(char *numstr, unsigned long long number, int base, char *base_chars)
{
	if (sizeof(numstr) - 1 < (unsigned long)count_of_ull(number, base))
		return ;
	if (number >= (unsigned long long)base)
		rec_itoa_ull(numstr, number / base, base, base_chars);
	numstr[count_of_ull(number, base) - 1] = base_chars[number % base];
}
