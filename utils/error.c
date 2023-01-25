#include "../ls.h"

int	err_printer_and_cleaner(t_ls *ls, char *message)
{
	write(CSTDERR, message, ft_strlen(message));
	write(CSTDERR, "\n", 1);
	clear_ls(ls);
	return (-1);
}

