#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include <unistd.h>

# include "../libs/libft/libft.h"

int		len_double_char_array(const char **darr);
void	free_double_char_array(char **arr);
void	err_printer_and_cleaner(t_ls *ls, int errcode, int exitcode);
void	**calloca_to_2d(size_t size);

#endif
