#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include <unistd.h>

# include "../libs/libft/libft.h"

# define STDIN	0
# define STDOUT	1

int		len_double_array(char **darray);
void	free_double_array(char **array);
void	print_error(char *error);

#endif