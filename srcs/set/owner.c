#include "../../ls.h"

void	set_owner(char oname[255 + 1], uid_t st_uid)
{
	get_owner(st_uid, oname);
}
