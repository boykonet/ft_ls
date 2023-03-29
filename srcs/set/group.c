#include "../../ls.h"

void	set_group(char group[255 + 1], gid_t st_gid)
{
	struct group	*grp;

	grp = getgrgid(st_gid);
	if (grp == NULL)
		rec_itoa_ull(group, st_gid, 10, "0123456789");
	else
		ft_strlcpy(group, grp->gr_name, 255);
}
