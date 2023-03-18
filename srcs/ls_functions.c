#include "../ls.h"

void	init_ls(t_ls *ls)
{
	ls->flags = 0;
	ls->files = NULL;
	ls->dirs = NULL;
	ls->epatterns = NULL;
}

void	clear_ls(t_ls *ls)
{
	ls->flags = 0;
	if (ls->files)
	{
		free_2array((void **)ls->files);
		ls->files = NULL;
	}
	if (ls->dirs)
	{
		free_2array((void **)ls->dirs);
		ls->dirs = NULL;
	}
	if (ls->epatterns)
	{
		ft_lstclear(&ls->epatterns, del_pattern);
		ls->epatterns = NULL;
	}
}

