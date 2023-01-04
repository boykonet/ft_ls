#include "utils.h"

void	print_error(char *error)
{
	write(STDOUT, "Error: ", 7);
	write(STDOUT, error, ft_strlen(error));
}
