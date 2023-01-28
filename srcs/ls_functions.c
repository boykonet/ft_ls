#include "../ls.h"

int	init_ls(t_ls *ls)
{
	ls->folders = NULL;
	ls->flags = malloc(sizeof(char) * MAX_COUNT_FLAGS_PER_COMMAND);
	if (ls->flags == NULL)
		return (-1);
	ft_memcpy(ls->sflags, "Ralrt", MAX_COUNT_FLAGS_PER_COMMAND);
	ft_memcpy(ls->func, (f[MAX_COUNT_FLAGS_PER_COMMAND]){&handle_recursive_flag, &handle_a_flag, &handle_l_flag, &handle_r_flag, &handle_t_flag}, sizeof(void*) * MAX_COUNT_FLAGS_PER_COMMAND);
	return (0);
}

void	clear_ls(t_ls *ls)
{
	if (ls->flags)
		free(ls->flags);
	if (ls->folders)
		free_double_char_array(ls->folders);
}

