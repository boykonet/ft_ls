#include "../../ls.h"

void	set_number_of_links(nlink_t st_nlinks, char *links)
{
	if (links == NULL)
		return ;
	ft_bzero(links, sizeof(links));
	rec_itoa_ull(links, st_nlinks, 10, DECIMAL_BASE_STR);
}