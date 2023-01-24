#include "utils.h"

int	err_printer_and_cleaner(t_ls *ls, char *message)
{
	write(stderr, message, ft_strlen(message));
	write(stderr, "\n", 1);
	clear_ls(ls);
	return (-1);
}

