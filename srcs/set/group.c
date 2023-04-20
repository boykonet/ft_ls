#include "../../ls.h"

void	set_group(char group[STRING_SIZE + 1], gid_t st_gid)
{
	struct group	*grp;

	grp = getgrgid(st_gid);
	if (grp == NULL)
		rec_itoa_ull(group, st_gid, 10, DECIMAL_BASE_STR);
	else
		ft_strlcpy(group, grp->gr_name, STRING_SIZE);
}
