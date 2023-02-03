#include "../ls.h"

char *get_user(uid_t uid)
{
	struct passwd *pwd;

	if ((pwd = getpwuid(uid)) == NULL)
		return (NULL);
	return (pwd->pw_name);
}

char *get_group(gid_t gid)
{
	struct group *grp;

	if ((grp = getgrgid(gid)) == NULL)
		return (NULL);
	return (grp->gr_name);
}
