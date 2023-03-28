#include "../../ls.h"

void	set_group(char group[255 + 1], gid_t st_gid)
{
	get_group(st_gid, group);
}
