#include "../ls.h"

int	init_ls(t_ls *ls)
{
	ls->files = NULL;
	ls->flags = ft_calloc(MAX_FLAGS + 1, sizeof(char));
	if (ls->flags == NULL)
		return (-1);
//	ft_memcpy(ls->sflags, "Ralrt", MAX_FLAGS);
//	ft_memcpy(ls->func, (f[MAX_FLAGS]){&handle_recursive_flag, &handle_a_flag, &handle_l_flag, &handle_r_flag, &handle_t_flag}, sizeof(void*) * MAX_FLAGS);
	return (0);
}

void	clear_ls(t_ls *ls)
{
	if (ls->flags)
		free(ls->flags);
	if (ls->files)
		free_double_char_array(ls->files);
}

