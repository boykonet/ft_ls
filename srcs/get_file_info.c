#include "../ls.h"

char *get_user(uid_t uid)
{
	struct passwd *pwd;

	pwd = getpwuid(uid);
	if (pwd == NULL)
		return (ft_itoa(uid));
	return (ft_strdup(pwd->pw_name));
}

char *get_group(gid_t gid)
{
	struct group *grp;

	if ((grp = getgrgid(gid)) == NULL)
		return (ft_itoa(gid));
	return (ft_strdup(grp->gr_name));
}
