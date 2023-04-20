#include "../../ls.h"

void	set_owner(char owner[STRING_SIZE + 1], uid_t st_uid)
{
	struct passwd *pwd;

	pwd = getpwuid(st_uid);
	if (pwd == NULL)
		rec_itoa_ull(owner, st_uid, 10, DECIMAL_BASE_STR);
	else
		ft_strlcpy(owner, pwd->pw_name, STRING_SIZE);
}
