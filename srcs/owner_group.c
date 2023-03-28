#include "../ls.h"

void	get_owner(uid_t uid, char owner[255 + 1])
{
	struct passwd *pwd;

	pwd = getpwuid(uid);
	if (pwd == NULL)
		rec_itoa_ull(owner, uid, 10, "0123456789");
	else
		ft_strlcpy(owner, pwd->pw_name, 255);
}

int		max(int first, int second)
{
	return first > second ? first : second;
}

void	get_group(gid_t gid, char group[255 + 1])
{
	struct group	*grp;

	grp = getgrgid(gid);
	if (grp == NULL)
		rec_itoa_ull(group, gid, 10, "0123456789");
	else
		ft_strlcpy(group, grp->gr_name, 255);
}
