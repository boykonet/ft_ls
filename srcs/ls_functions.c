#include "../ls.h"

void	init_ls(t_ls *ls)
{
	int	i;

	i = 0;
	while (i < MAX_FLAGS + 1)
		ls->flags[i++] = '\0';
	ls->files = NULL;
	init_err(&ls->err);
}

void	clear_ls(t_ls *ls)
{
	int	i;

	i = 0;
	while (i < MAX_FLAGS + 1)
		ls->flags[i++] = '\0';
	if (ls->files)
		free_double_char_array(ls->files);
	clear_err(&ls->err);
}

