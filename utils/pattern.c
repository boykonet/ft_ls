#include "../ls.h"

t_pattern	*new_pattern(char *pattern, char *replacement)
{
	t_pattern	*p;

	p = ft_calloc(1, sizeof(t_pattern));
	if (!p)
		return (NULL);
	p->pattern = ft_strdup(pattern);
	if (!p->pattern)
	{
		del_pattern(p);
		return (NULL);
	}
	p->replacement = ft_strdup(replacement);
	if (!p->replacement)
	{
		del_pattern(p);
		return (NULL);
	}
	return (p);
}

//void	init_pattern(t_pattern *pattern)
//{
//	if (!pattern)
//		return ;
//	pattern->pattern = NULL;
//	pattern->replacement = NULL;
//}

void	clear_pattern(t_pattern *p)
{
	if (!p)
		return ;
	if (p->pattern)
	{
		free(p->pattern);
		p->pattern = NULL;
	}
	if (p->replacement)
	{
		free(p->replacement);
		p->replacement = NULL;
	}
}

void	del_pattern(void *node)
{
	if (!node)
		return ;
	clear_pattern((t_pattern*)node);
	free(node);
	node = NULL;
}
