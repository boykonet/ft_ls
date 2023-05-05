/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pattern.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: gkarina <gkarina@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/05 14:23:17 by gkarina       #+#    #+#                 */
/*   Updated: 2023/05/05 14:23:17 by gkarina       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ls.h"

void	add_pattern(t_pattern p[1], char *pattern, char *replacement)
{
	ft_bzero(p->pattern, sizeof(p->pattern));
	ft_bzero(p->replacement, sizeof(p->replacement));
	ft_strlcpy(p->pattern, pattern, STRING_SIZE);
	ft_strlcpy(p->replacement, replacement, STRING_SIZE);
}

void	replace_one_pattern(char *dest, t_pattern pattern[1])
{
	char	*pbegin, *pend;
	int		bsize, asize;
	size_t	lpattern, lrepl;

	if (dest == NULL)
		return ;
	lpattern = ft_strlen(pattern[0].pattern);
	lrepl = ft_strlen(pattern[0].replacement);

	pbegin = ft_strnstr(dest, pattern[0].pattern, ft_strlen(dest));
	if (!pbegin)
		return ;
	pend = pbegin + lpattern;

	bsize = (int)(pbegin - dest);
	asize = (int)((dest + ft_strlen(dest)) - pend);
	ft_memmove(pbegin + lrepl, pbegin + lpattern, asize);
	ft_memcpy(pbegin, pattern[0].replacement, lrepl);
	dest[bsize + lrepl + asize] = '\0';
}

void	replace_pattern(char *dest, const char *src, t_pattern patterns[MAX_REPL_PATTERNS], size_t count)
{
	size_t	i;

	i = 0;
	ft_memcpy(dest, src, ft_strlen(src));
	while (i < count && i < MAX_REPL_PATTERNS)
	{
		replace_one_pattern(dest, &patterns[i]);
		i++;
	}
}
