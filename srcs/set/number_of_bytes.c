#include "../../ls.h"

void	set_number_of_bytes(off_t st_size, char *bytes)
{
	if (bytes == NULL)
		return ;
	ft_bzero(bytes, sizeof(bytes));
	rec_itoa_ull(bytes, st_size, 10, "0123456789");
}