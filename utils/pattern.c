#include "../ls.h"

//t_pattern	*new_pattern(char *pattern, char *replacement)
//{
//	t_pattern	*p;
//
//	p = ft_calloc(1, sizeof(t_pattern));
//	if (!p)
//		return (NULL);
//	p->pattern = ft_strdup(pattern);
//	if (!p->pattern)
//	{
//		del_pattern(p);
//		return (NULL);
//	}
//	p->replacement = ft_strdup(replacement);
//	if (!p->replacement)
//	{
//		del_pattern(p);
//		return (NULL);
//	}
//	return (p);
//}

//void	clear_pattern(t_pattern *p)
//{
//	if (!p)
//		return ;
//	if (p->pattern)
//	{
//		free(p->pattern);
//		p->pattern = NULL;
//	}
//	if (p->replacement)
//	{
//		free(p->replacement);
//		p->replacement = NULL;
//	}
//}
//
//void	del_pattern(void *node)
//{
//	if (!node)
//		return ;
//	clear_pattern((t_pattern*)node);
//	free(node);
//	node = NULL;
//}

void		replace_one_pattern(char *dest, t_pattern pattern[1])
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

void		replace_pattern(char *dest, const char *src, t_pattern patterns[MAX_REPL_PATTERNS], size_t count)
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
