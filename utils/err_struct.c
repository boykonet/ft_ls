#include "../ls.h"

void	init_err(t_err *err)
{
	if (!err)
		return ;
	err->message = NULL;
	err->exitcode = 0;
	err->patterns = NULL;
}

void	clear_err(t_err *err)
{
	if (!err)
		return ;
	if (err->message)
	{
		free(err->message);
		err->message = NULL;
	}
	if (err->exitcode)
		err->exitcode = 0;
	if (err->patterns)
	{
		ft_lstclear(&err->patterns, del_pattern);
		err->patterns = NULL;
	}
}
