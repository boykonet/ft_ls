#include "../ls.h"

int	init_ls(t_ls *ls)
{
	ls->folders = NULL;
	if (alloc_to((void**)&ls->flags, MAX_COUNT_FLAGS_PER_COMMAND) == -1)
		return (-1);
	return (0);
}

void	clear_ls(t_ls *ls)
{
	if (ls->flags)
		free(ls->flags);
	if (ls->folders)
		free_double_char_array(ls->folders);
}

