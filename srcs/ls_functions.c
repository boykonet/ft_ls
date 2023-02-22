#include "../ls.h"

void	init_ls(t_ls *ls)
{
	ls->flags = NULL;
	ls->filenames = NULL;
	ls->files = NULL;
	ls->dirs = NULL;
	init_err(&ls->err);
}

void	clear_ls(t_ls *ls)
{
	if (ls->flags)
	{
		free(ls->flags);
		ls->flags = NULL;
	}
	if (ls->filenames)
	{
		free_2_pointer_array((void**)ls->filenames);
		ls->filenames = NULL;
	}
	if (ls->files)
	{
		free_2_pointer_array((void**)ls->files);
		ls->files = NULL;
	}
	if (ls->dirs)
	{
		free_2_pointer_array((void**)ls->dirs);
		ls->dirs = NULL;
	}
	clear_err(&ls->err);
}

