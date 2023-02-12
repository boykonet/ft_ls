#include "../ls.h"

void	init_pattern(t_pattern *pattern)
{
	if (!pattern)
		return ;
	pattern->pattern = NULL;
	pattern->replacement = NULL;
}

void	del_pattern(void *node)
{
	t_pattern	*p;

	p = (t_pattern*)node;
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
