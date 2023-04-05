#include "../../ls.h"

void	set_type(unsigned int *type, mode_t st_mode)
{
	if (type == NULL)
		return ;
	*type = (unsigned int)(st_mode & S_IFMT);
}
